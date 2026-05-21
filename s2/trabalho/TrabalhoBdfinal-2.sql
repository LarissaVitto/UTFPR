--BARBARA RODRIGUES DE OLIVEIRA
--GABRIEL DE LIMA PEREIRA
--LARISSA REGINA COSTA VITTO
--REGINA PEGORARO CAPITANIO
--VITOR ALEXANDRE SPANHOLI PINTO

--Crie o script SQL para a criação do banco de dados e das tabelas;
CREATE TABLE Pessoa (
    pk_cod_pessoa INT PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
    nome VARCHAR(150) NOT NULL,
    rg VARCHAR(20),
    data_nascimento DATE
);

CREATE TABLE Atracao (
    pk_cod_atracao INT PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
    nome VARCHAR(150) NOT NULL,
    max_pessoas INT,
    situacao VARCHAR(50)
);

CREATE TABLE Visita (
    fk_cod_pessoa INT NOT NULL,
    fk_cod_atracao INT NOT NULL,
    hora_entrada TIME NOT NULL,
    hora_saida TIME,
    PRIMARY KEY (fk_cod_pessoa, fk_cod_atracao),
    FOREIGN KEY (fk_cod_pessoa) REFERENCES Pessoa(pk_cod_pessoa),
    FOREIGN KEY (fk_cod_atracao) REFERENCES Atracao(pk_cod_atracao)
);

CREATE TABLE Turno (
    pk_cod_turno INT PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
    horario_turno VARCHAR(50) NOT NULL
);

CREATE TABLE Funcionario (
    pk_cod_funcionario INT PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
    fk_cod_turno INT NOT NULL,
    salario DECIMAL(10,2),
    nome VARCHAR(150) NOT NULL,
    rg VARCHAR(20),
    cpf VARCHAR(20),
    rua VARCHAR(100),
    numero VARCHAR(10),
    bairro VARCHAR(100),
    complemento VARCHAR(100),
    cidade VARCHAR(100),
    estado VARCHAR(50),
    pais VARCHAR(50),
    cep VARCHAR(20),
    FOREIGN KEY (fk_cod_turno) REFERENCES Turno(pk_cod_turno)
);

CREATE TABLE Ingresso (
    pk_cod_ingresso INT PRIMARY KEY GENERATED ALWAYS AS IDENTITY,
    fk_cod_funcionario INT NOT NULL,
    tipo VARCHAR(50),
    preco DECIMAL(10,2),
    data_compra DATE,
    hora_venda TIME,
    FOREIGN KEY (fk_cod_funcionario) REFERENCES Funcionario(pk_cod_funcionario)
);
--Crie o script SQL que insira pelo menos 10 registros distintos em cada tabela. Cinco ingressos devem corresponder a entrada inteira e os demais a meia entrada.

INSERT INTO Pessoa (nome, rg, data_nascimento) VALUES
('Maria Joaquina Medsen','1111111', '2000-12-28'),
('Cirilo Rivera','1111112','2003-04-13'),
('Valéria Ferreira','1111113','2002-05-22'),
('Marcelina Guerra','1111114','2002-06-26'),
('Paulo Guerra','1111115','2000-12-29'),
('Jaime Palillo','1111116','1999-09-02'),
('Kokimoto Mishima','1111117','2004-05-23'),
('Jorge Cavalieri','1111118','2002-04-25'),
('Davi Rabinovich','1111119','2002-12-17'),
('Laura Gianolli','1111120','2003-05-13');

INSERT INTO Atracao (nome, max_pessoas, situacao) VALUES
('Roda Gigante', 40, 'Ativa'),
('Montanha Russa', 20, 'Manutenção'),
('Carrossel', 30, 'Ativa'),
('Casa do Terror', 15, 'Ativa'),
('Autorama', 10, 'Ativa'),
('Simulador 4D', 12, 'Ativa'),
('Barco Viking', 25, 'Ativa'),
('Trem Fantasma', 18, 'Ativa'),
('Splash', 22, 'Manutenção'),
('Torre de Queda', 16, 'Ativa');

INSERT INTO Turno (horario_turno) VALUES
('Manhã'),
('Tarde'),
('Noite'),
('Integral');

INSERT INTO Funcionario (
    fk_cod_turno, salario, nome, rg, cpf, rua, numero, bairro, complemento,
    cidade, estado, pais, cep
) VALUES
(1, 2500.00, 'Marcos Vieira', '1231231', '11111111111', 'Rua Azul', '10', 'Centro', '', 'Curitiba', 'PR', 'Brasil', '80010-000'),
(2, 2600.00, 'Paulo Ricardo', '2342342', '22222222222', 'Rua Verde', '22', 'Jardins', '', 'Curitiba', 'PR', 'Brasil', '80010-000'),
(3, 2700.00, 'Juliana Alves', '3453453', '33333333333', 'Rua Amarela', '33', 'Batel', 'Ap 2', 'Curitiba', 'PR', 'Brasil', '80010-000'),
(4, 3000.00, 'Rita Gomes', '4564564', '44444444444', 'Rua Vermelha', '12', 'Centro', '', 'Curitiba', 'PR', 'Brasil', '80010-000'),
(1, 2800.00, 'Carlos Alberto', '5675675', '55555555555', 'Rua Roxa', '15', 'Hauer', '', 'Curitiba', 'PR', 'Brasil', '80010-000'),
(2, 2650.00, 'Fernanda Costa', '6786786', '66666666666', 'Rua Lilás', '88', 'Água Verde', '', 'Curitiba', 'PR', 'Brasil', '80010-000'),
(3, 2550.00, 'Gustavo Silva', '7897897', '77777777777', 'Rua Rosa', '19', 'Boqueirão', '', 'Curitiba', 'PR', 'Brasil', '80010-000'),
(4, 3100.00, 'Helena Duarte', '8908908', '88888888888', 'Rua Laranja', '23', 'Centro Cívico', '', 'Curitiba', 'PR', 'Brasil', '80010-000'),
(1, 2950.00, 'Roberto Lima', '9019019', '99999999999', 'Rua Preta', '45', 'Portão', '', 'Curitiba', 'PR', 'Brasil', '80010-000'),
(2, 2400.00, 'Patrícia Souza', '0120120', '10101010101', 'Rua Branca', '55', 'Santa Felicidade', '', 'Curitiba', 'PR', 'Brasil', '80010-000');

INSERT INTO Visita (fk_cod_pessoa, fk_cod_atracao, hora_entrada, hora_saida) VALUES
(1, 1, '10:00', '10:30'),
(2, 3, '11:00', '11:20'),
(3, 4, '12:00', '12:50'),
(4, 5, '13:00', '13:40'),
(5, 6, '14:00', '14:25'),
(6, 7, '15:00', '15:30'),
(7, 8, '16:00', '16:35'),
(8, 9, '17:00', '17:40'),
(9, 10, '18:00', '18:30'),
(10, 1, '19:00', '19:20');

INSERT INTO Ingresso (fk_cod_funcionario, tipo, preco, data_compra, hora_venda) VALUES
(1, 'Inteira', 60.00, '2025-01-15', '09:10'),
(1, 'Inteira', 60.00, '2025-01-15', '09:20'),
(2, 'Inteira', 60.00, '2025-01-16', '10:00'),
(4, 'Inteira', 60.00, '2025-01-16', '11:00'),
(7, 'Inteira', 60.00, '2025-01-17', '12:30'),

(3, 'Meia', 30.00, '2025-01-17', '13:00'),
(3, 'Meia', 30.00, '2025-01-18', '14:25'),
(8, 'Meia', 30.00, '2025-01-18', '15:00'),
(5, 'Meia', 30.00, '2025-01-19', '16:10'),
(10, 'Meia', 30.00, '2025-01-19', '17:40');

--Escreva a consulta SQL que liste todos os ingressos de meia entrada comprados durante o ano de 2025;
SELECT * FROM ingresso
WHERE tipo = 'Meia'
AND data_compra >= '2025-01-01'
AND data_compra<= '2025-12-31';

--Escreva a consulta SQL que liste todos os ingressos de entrada inteira comprados durante o ano de 2025;

SELECT *
FROM Ingresso
WHERE tipo = 'Inteira'
  AND data_compra >= '2025-01-01'
  AND data_compra <= '2025-12-31';

--Escreva a consulta SQL que liste todas as atrações visitadas com ingressos de meia entrada;

SELECT a.nome AS atracao
FROM Atracao a
JOIN Visita v ON a.pk_cod_atracao = v.fk_cod_atracao
JOIN Ingresso i ON i.tipo = 'Meia'
GROUP BY a.nome;

--Escreva a consulta SQL que liste as três atrações mais visitadas durante o ano de 2025;

SELECT a.nome AS atracao,
       COUNT(v.fk_cod_atracao) AS total_visitas
FROM Visita AS v
JOIN Atracao AS a ON a.pk_cod_atracao = v.fk_cod_atracao
GROUP BY a.nome
ORDER BY total_visitas DESC
LIMIT 3;

--Escreva a consulta SQL que liste os 3 funcionários que mais venderam ingressos durante o ano de 2025;

SELECT f.nome AS funcionario,
       COUNT(i.pk_cod_ingresso) AS total_vendas
FROM Ingresso AS i
JOIN Funcionario AS f ON f.pk_cod_funcionario = i.fk_cod_funcionario
WHERE i.data_compra >= '2025-01-01' 
  AND i.data_compra < '2026-01-01'
GROUP BY f.nome
ORDER BY total_vendas DESC
LIMIT 3;