-- =========================================================
-- QUESTÕES PRÁTICAS
-- =========================================================

-- =========================================================
-- QUESTÃO 1 (BLOCO ANÔNIMO)
-- =========================================================
-- Enunciado:
-- Crie um bloco anônimo em PL/pgSQL usando DO $$ ... $$ que:
--   1) declare uma variável inteira;
--   2) conte quantos municípios existem cadastrados na tabela municipio;
--   3) armazene esse valor na variável;
--   4) exiba uma mensagem com RAISE NOTICE.
--
-- Requisitos mínimos:
--   * usar DECLARE
--   * usar SELECT COUNT(*)
--   * usar INTO
--   * usar RAISE NOTICE
--
-- Hint de entrada:
--   Não há parâmetro de entrada, pois se trata de um bloco anônimo.
--
-- Hint de saída:
--   Deve aparecer uma mensagem semelhante a:
--   Total de municípios cadastrados: 4
--
-- Espaço para resolução:

DO $$
DECLARE
	 TOTAL_MUNICIPIOS INT;
BEGIN
	SELECT COUNT(*) INTO TOTAL_MUNICIPIOS FROM municipio;
	RAISE NOTICE 'Total de municípios cadastrados: %', TOTAL_MUNICIPIOS;
END $$;


-- =========================================================
-- QUESTÃO 2 (FUNCTION SIMPLES)
-- =========================================================
-- Enunciado:
-- Crie uma function chamada saudacao_municipio que receba como parâmetro
-- o nome de um município (texto) e retorne uma mensagem de saudação.
--
-- Requisitos mínimos:
--   * a function deve receber 1 parâmetro do tipo TEXT
--   * a function deve retornar TEXT
--   * a mensagem deve concatenar um texto fixo com o nome recebido
--
-- Hint de entrada:
--   Exemplo de chamada:
--   SELECT saudacao_municipio('Dois Vizinhos');
--
-- Hint de saída:
--   Resultado esperado:
--   Bem-vindo ao município de Dois Vizinhos
--
-- Espaço para resolução:

CREATE OR REPLACE FUNCTION SAUDACAO_MUNICIPIO(NOME_MUNICIPIO TEXT) 
RETURNS TEXT AS $$
BEGIN
    RETURN 'Bem-vindo ao município de ' || NOME_MUNICIPIO;
END;
$$ LANGUAGE plpgsql;

-- Teste:
 SELECT saudacao_municipio('Dois Vizinhos');


-- =========================================================
-- QUESTÃO 3 (FUNCTION COM SELECT INTO)
-- =========================================================
-- Enunciado:
-- Crie uma function chamada resumo_municipio que receba o id de um município
-- e retorne uma frase contendo:
--   * o nome do município
--   * a população desse município
--
-- A function deve consultar a tabela municipio, capturar os valores com
-- SELECT INTO e montar a frase final em texto.
--
-- Requisitos mínimos:
--   * declarar variáveis locais
--   * usar SELECT ... INTO ...
--   * consultar a tabela municipio pelo id
--   * retornar um texto formatado
--
-- Hint de entrada:
--   Exemplo de chamada:
--   SELECT resumo_municipio(1);
--
-- Hint de saída:
--   Resultado esperado para id 1:
--   Dois Vizinhos possui 44869 habitantes
--
-- Observação:
--   Considere, nesta atividade, que o id informado existe.
--
-- Espaço para resolução:
CREATE OR REPLACE FUNCTION RESUMO_MUNICIPIO(ID_MUN INT)
	RETURNS TEXT AS $$
DECLARE
	NOME_MUN VARCHAR(100);
	QTD_POP INT;
BEGIN
	SELECT NOME, POPULACAO INTO NOME_MUN, QTD_POP FROM MUNICIPIO WHERE ID_MUNICIPIO = ID_MUN;
	RETURN NOME_MUN || ' possui ' || QTD_POP || ' habitantes ';
END;
$$
LANGUAGE plpgsql;

-- Teste: 
SELECT resumo_municipio(1);

-- =========================================================
-- QUESTÃO 4 (FUNCTION COM IF / ELSIF / ELSE)
-- =========================================================
-- Enunciado:
-- Crie uma function chamada classificar_area que receba um valor numérico
-- referente à área plantada e retorne uma classificação textual.
--
-- Regras de classificação:
--   * se a área for menor que 5      -> retornar 'Pequena'
--   * se a área for de 5 até 15      -> retornar 'Média'
--   * se a área for maior que 15     -> retornar 'Grande'
--
-- Requisitos mínimos:
--   * usar IF / ELSIF / ELSE
--   * receber parâmetro numérico
--   * retornar texto
--
-- Hint de entrada:
--   SELECT classificar_area(2.4);
--   SELECT classificar_area(11.6);
--   SELECT classificar_area(22.1);
--
-- Hint de saída:
--   Para 2.4  -> Pequena
--   Para 11.6 -> Média
--   Para 22.1 -> Grande
--
-- Espaço para resolução:

CREATE OR REPLACE FUNCTION CLASSIFICAR_AREA(AREA NUMERIC) 
RETURNS TEXT AS $$
BEGIN
    IF AREA < 5 THEN
        RETURN 'Pequena';
    ELSIF AREA BETWEEN 5 AND 15 THEN
        RETURN 'Média';
    ELSE
        RETURN 'Grande';
    END IF;
END;
$$ LANGUAGE plpgsql;

-- Teste: 
SELECT classificar_area(2.4);
SELECT classificar_area(11.6);
SELECT classificar_area(22.1);

-- =========================================================
-- QUESTÃO 5 (FUNCTION COM LOOP FOR)
-- =========================================================
-- Enunciado:
-- Crie uma function chamada listar_culturas que receba o id de um município
-- e percorra, com um laço FOR, todas as culturas plantadas nesse município.
--
-- A function deve:
--   * fazer um JOIN entre area_plantada e tipo_cultura
--   * selecionar as culturas associadas ao município informado
--   * percorrer os resultados com FOR
--   * exibir cada cultura com RAISE NOTICE
--
-- Requisitos mínimos:
--   * usar variável do tipo RECORD
--   * usar FOR ... IN SELECT ...
--   * usar JOIN
--   * usar RAISE NOTICE
--   * a function pode retornar VOID
--
-- Hint de entrada:
--   Exemplo de chamada:
--   SELECT listar_culturas(1);
--
-- Hint de saída:
--   Para o município de id 1, devem aparecer notices semelhantes a:
--   Cultura: Soja
--   Cultura: Milho
--   Cultura: Feijão
--   Cultura: Hortaliças
--
-- Observação:
--   A ordem pode seguir a ordem retornada pela consulta, ou ser ajustada
--   com ORDER BY, se desejar.
--
-- Espaço para resolução:

CREATE OR REPLACE FUNCTION LISTAR_CULTURAS(ID_MUN INT) 
RETURNS VOID AS $$
DECLARE
    SALVAR RECORD;
BEGIN
    FOR SALVAR IN 
        SELECT TPC.NOME
        FROM AREA_PLANTADA AP
        JOIN TIPO_CULTURA TPC ON AP.ID_TIPO_CULTURA = TPC.ID_TIPO_CULTURA
        WHERE AP.ID_MUNICIPIO = ID_MUN ORDER BY TPC.NOME
    LOOP
        RAISE NOTICE 'Cultura: %', SALVAR.NOME;
    END LOOP;
END;
$$ LANGUAGE plpgsql;

-- Teste: 
SELECT listar_culturas(1);

-- =========================================================
-- QUESTÃO 6 (PROCEDURE)
-- =========================================================
-- Enunciado:
-- Crie uma procedure chamada reajustar_area_pequena que receba um percentual
-- numérico e atualize as áreas plantadas menores que 5 km².
--
-- A procedure deve:
--   * receber um percentual como parâmetro
--   * localizar registros da tabela area_plantada com area_km2 < 5
--   * aumentar essas áreas de acordo com o percentual informado
--   * exibir, ao final, quantos registros foram atualizados
--
-- Requisitos mínimos:
--   * usar CREATE PROCEDURE
--   * usar UPDATE
--   * usar o parâmetro percentual no cálculo
--   * usar GET DIAGNOSTICS ... ROW_COUNT
--   * usar RAISE NOTICE
--
-- Hint de entrada:
--   Exemplo de execução:
--   CALL reajustar_area_pequena(10);
--
-- Hint de saída:
--   Antes da execução, existem áreas menores que 5 km² como 2.40, 4.30 e 1.90.
--   Após a execução com 10, essas áreas devem ser reajustadas em 10%.
--   Também deve aparecer uma mensagem como:
--   Registros atualizados: 3
--
-- Consulta opcional para conferir antes/depois:
--   SELECT * FROM area_plantada WHERE area_km2 < 5 OR id_area_plantada IN (4, 7, 10);
--
-- Espaço para resolução:

CREATE OR REPLACE PROCEDURE REAJUSTAR_AREA_PEQUENA(PERCENTUAL NUMERIC)
AS $$
DECLARE
    REG_ATUALIZADOS INT;
BEGIN
    UPDATE AREA_PLANTADA
    SET AREA_KM2 = AREA_KM2 * (1 + PERCENTUAL / 100)
    WHERE AREA_KM2 < 5;
    GET DIAGNOSTICS REG_ATUALIZADOS = ROW_COUNT;
    RAISE NOTICE 'Registros atualizados: %', REG_ATUALIZADOS;
END;
$$ LANGUAGE plpgsql;

-- Teste: 
CALL reajustar_area_pequena(10);

-- =========================================================
-- 5) TESTES SUGERIDOS APÓS AS IMPLEMENTAÇÕES
-- =========================================================
-- Estes comandos podem ser usados pelos estudantes após escreverem
-- suas soluções, para validar cada item.

-- Questão 2:
SELECT saudacao_municipio('Verê');

-- Questão 3:
SELECT resumo_municipio(2);

-- Questão 4:
 SELECT classificar_area(4.30);
SELECT classificar_area(9.70);
SELECT classificar_area(18.50);

-- Questão 5:
SELECT listar_culturas(1);

-- Questão 6:
CALL reajustar_area_pequena(10);
