CREATE TABLE clientes (
   id SERIAL PRIMARY KEY,
   nome VARCHAR(200) NOT NULL,
   cpf VARCHAR(14) UNIQUE NOT NULL,
   created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
CREATE TABLE contas (
   id SERIAL PRIMARY KEY,
   cliente_id INTEGER NOT NULL REFERENCES clientes(id),
   saldo NUMERIC(12,2) NOT NULL CHECK (saldo >= 0),
   ativa BOOLEAN DEFAULT TRUE,
   created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
CREATE TABLE transferencias (
   id SERIAL PRIMARY KEY,
   conta_origem_id INTEGER NOT NULL REFERENCES contas(id),
   conta_destino_id INTEGER NOT NULL REFERENCES contas(id),
   valor NUMERIC(12,2) NOT NULL CHECK (valor > 0),
   data_transferencia TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
CREATE TABLE auditoria_transferencias (
   id SERIAL PRIMARY KEY,
   transferencia_id INTEGER,
   usuario_execucao VARCHAR(100),
   operacao VARCHAR(50),
   data_evento TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
   detalhes TEXT
);
---------- POPULANDO ----------
-- 100 clientes
INSERT INTO clientes (nome, cpf)
SELECT
  'Cliente ' || i,
  LPAD(i::text, 11, '0')
FROM generate_series(1, 100) AS i;
-- 100 contas
INSERT INTO contas (cliente_id, saldo, ativa)
SELECT
  id,
  ROUND((RANDOM() * 10000)::numeric, 2),
  TRUE
FROM clientes;
-- Parte 2 – Implementação de Transferências
---------- FUNCAO ----------
CREATE OR REPLACE FUNCTION realizar_transferencia(
    p_conta_origem INTEGER,
    p_conta_destino INTEGER,
    p_valor NUMERIC
)
RETURNS TEXT
LANGUAGE plpgsql
AS $$
DECLARE
    v_saldo NUMERIC;
    v_transferencia_id INTEGER;
BEGIN
    -- 1. Validar existência das contas
    IF NOT EXISTS (
        SELECT 1
        FROM contas
        WHERE id = p_conta_origem
    ) THEN
        RAISE EXCEPTION 'Conta de origem inexistente.';
    END IF;

    IF NOT EXISTS (
        SELECT 1
        FROM contas
        WHERE id = p_conta_destino
    ) THEN
        RAISE EXCEPTION 'Conta de destino inexistente.';
    END IF;

    -- 2. Verificar se ambas estão ativas
    IF NOT EXISTS (
        SELECT 1
        FROM contas
        WHERE id = p_conta_origem
        AND ativa = TRUE
    ) THEN
        RAISE EXCEPTION 'Conta de origem inativa.';
    END IF;

    IF NOT EXISTS (
        SELECT 1
        FROM contas
        WHERE id = p_conta_destino
        AND ativa = TRUE
    ) THEN
        RAISE EXCEPTION 'Conta de destino inativa.';
    END IF;
-- Parte 3 – Tratamento de Exceções
---------- Validações extras exigidas na Parte 3 ----------
    IF p_conta_origem = p_conta_destino THEN
        RAISE EXCEPTION 'Transferência para a própria conta não é permitida.';
    END IF;

    IF p_valor <= 0 THEN
        RAISE EXCEPTION 'Valor da transferência deve ser maior que zero.';
    END IF;

    -- 3. Verificar saldo suficiente
    SELECT saldo
    INTO v_saldo
    FROM contas
    WHERE id = p_conta_origem
    FOR UPDATE;

    IF v_saldo < p_valor THEN
        RAISE EXCEPTION 'Saldo insuficiente.';
    END IF;

    -- 4. Debitar valor da conta de origem
    UPDATE contas
    SET saldo = saldo - p_valor
    WHERE id = p_conta_origem;

    -- 5. Creditar valor na conta de destino
    UPDATE contas
    SET saldo = saldo + p_valor
    WHERE id = p_conta_destino;

    -- 6. Registrar transferência
    INSERT INTO transferencias(
        conta_origem_id,
        conta_destino_id,
        valor
    )
    VALUES(
        p_conta_origem,
        p_conta_destino,
        p_valor
    )
    RETURNING id INTO v_transferencia_id;

    -- 7. Registrar evento de auditoria
    INSERT INTO auditoria_transferencias(
        transferencia_id,
        usuario_execucao,
        operacao,
        detalhes
    )
    VALUES(
        v_transferencia_id,
        CURRENT_USER,
        'TRANSFERENCIA',
        'Transferência de R$ ' || p_valor ||
        ' da conta ' || p_conta_origem ||
        ' para a conta ' || p_conta_destino
    );

    -- 8. Todas as operações executadas na mesma transação
    RETURN 'Transferência realizada com sucesso.';

IF p_conta_origem = p_conta_destino THEN
        RAISE EXCEPTION 'Transferência para a própria conta não é permitida.';
    END IF;

    IF p_valor <= 0 THEN
        RAISE EXCEPTION 'Valor da transferência deve ser maior que zero.';
    END IF;

END;
$$;

-- Parte 4 – Controle de Concorrência
-- sem bloqueio
-- Guia 1
BEGIN;
SELECT saldo FROM contas
WHERE cliente_id = 103;
UPDATE contas
SET saldo = saldo - 500
WHERE cliente_id = 103;
commit;
-- Guia 2
BEGIN;
SELECT saldo FROM contas
WHERE cliente_id = 103;
UPDATE contas
SET saldo = saldo + 700
WHERE cliente_id = 103;
--COM BLOQUEIO
-- Guia 1
begin;
SELECT *
FROM contas
WHERE cliente_id = 102
FOR UPDATE;
UPDATE contas
SET saldo = saldo + 200
WHERE cliente_id = 102;
--Guia 2
begin;
SELECT *
FROM contas
WHERE cliente_id = 102
FOR UPDATE;
UPDATE contas
SET saldo = saldo - 100
WHERE cliente_id = 102;

-- Parte 5 – Níveis de Isolamento
-- READ COMMITTED ----------
--TRANSACAO 1
BEGIN;

SET TRANSACTION ISOLATION LEVEL READ COMMITTED;

--TRANSACAO 2
BEGIN;

SET TRANSACTION ISOLATION LEVEL READ committed;

UPDATE contas
SET saldo = saldo + 100
WHERE cliente_id = 102;

commit;

--TRANSACAO 1
SELECT * FROM contas
WHERE cliente_id = 102;

-- SERIALIZABLE ----------
--TRANSACAO 1
BEGIN;

SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;

UPDATE contas
SET saldo = saldo - 300
WHERE cliente_id = 102;

commit;

--TRANSACAO 2
BEGIN;

SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;

UPDATE contas
SET saldo = saldo + 500
WHERE cliente_id = 102;

COMMIT;

-- Parte 6 – Segurança
---------- Operador ----------
create role Operador;
grant select on clientes, contas to Operador;
grant insert on transferencias to Operador;
grant usage on all sequences in schema public to Operador;
grant execute on function realizar_transferencia(integer, integer, numeric) to Operador;
revoke update on contas from Operador;
revoke delete on all tables in schema public from Operador;
---------- Gerente ----------
create role Gerente;
grant Operador to Gerente;
grant update on contas to Gerente;
grant select on auditoria_transferencias to Gerente;
---------- Auditor ----------
create role Auditor;
grant select on all tables in schema public to Auditor;

-- 1. TESTES DO PAPEL: OPERADOR
-- SELECT
SET ROLE Operador;
SELECT
   cli.id AS cliente_id,
   cli.nome,
   con.id AS conta_id,
   con.saldo
FROM clientes cli
JOIN contas con ON cli.id = con.cliente_id
LIMIT 1;
-- INSERT
INSERT INTO transferencias (conta_origem_id, conta_destino_id, valor) VALUES (1, 2, 5.00);
-- EXECUTE
SELECT realizar_transferencia(1, 2, 10.00);
-- UPDATE
UPDATE contas SET saldo = 999999 WHERE id = 1;
-- DELETE
DELETE FROM contas WHERE id = 1;
DELETE FROM clientes WHERE id = 1;
DELETE FROM transferencias WHERE id = 1;
RESET ROLE;
-- 2. TESTES DO PAPEL: GERENTE
SET ROLE Gerente;
-- SELECT
SELECT
   cli.id AS cliente_id,
   cli.nome,
   con.id AS conta_id,
   con.saldo
FROM clientes cli
JOIN contas con ON cli.id = con.cliente_id
LIMIT 1;
SELECT * FROM auditoria_transferencias LIMIT 1; --SELECT AUDITORIA
-- INSERT
INSERT INTO transferencias (conta_origem_id, conta_destino_id, valor) VALUES (1, 2, 5.00);
-- EXECUTE
SELECT realizar_transferencia(1, 2, 10.00);
-- UPDATE
UPDATE contas SET saldo = 999999 WHERE id = 1;
-- DELETE
DELETE FROM contas WHERE id = 1;
DELETE FROM clientes WHERE id = 1;
DELETE FROM transferencias WHERE id = 1;
RESET ROLE;
-- 3. TESTES DO PAPEL: AUDITOR
SET ROLE auditor;
-- SELECT
SELECT
   cli.nome AS nome_cliente_origem,
   con.id AS conta_origem,
   t.valor AS valor_transferido,
   a.detalhes AS registro_auditoria
FROM auditoria_transferencias a
JOIN transferencias t ON a.transferencia_id = t.id
JOIN contas con ON t.conta_origem_id = con.id
JOIN clientes cli ON con.cliente_id = cli.id
LIMIT 1;
RESET ROLE;

--Parte 7 - AUDITORIA
--CRIAR REGISTROS
SELECT realizar_transferencia(1, 2, 10.00);
SELECT realizar_transferencia(1, 2, 100);
SELECT realizar_transferencia(3, 4, 50);
--SELECT
SELECT *
FROM auditoria_transferencias;
