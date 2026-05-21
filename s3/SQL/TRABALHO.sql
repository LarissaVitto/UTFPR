DROP TABLE IF EXISTS Taxi;
DROP TABLE IF EXISTS Cliente;
DROP TABLE IF EXISTS Corrida;

CREATE TABLE Taxi(
  Placa VARCHAR(7) NOT NULL,
  Marca VARCHAR(30) NOT NULL,
  Modelo VARCHAR(30) NOT NULL,
  AnoFab INTEGER,
  Licenca VARCHAR(9),
  PRIMARY KEY(Placa)
);

CREATE TABLE Cliente(
  CliId VARCHAR(4) NOT NULL,
  Nome VARCHAR(80) NOT NULL,
  CPF VARCHAR(14) NOT NULL,
  PRIMARY KEY(CliId)
);

CREATE TABLE Corrida(
  CliId VARCHAR(4) NOT NULL,
  Placa VARCHAR(7) NOT NULL,
  DataPedido DATE NOT NULL,
  Valor NUMERIC(8,2) NOT NULL,
  PRIMARY KEY(CliId, Placa, DataPedido),
  FOREIGN KEY(CliId)
    REFERENCES Cliente(CliId)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION,
  FOREIGN KEY(Placa)
    REFERENCES Taxi(Placa)
      ON DELETE NO ACTION
      ON UPDATE NO ACTION
);

----------------------------------------------

INSERT INTO Cliente (CliId, Nome, CPF)
SELECT 
    '' || g, 
    'Cliente ' || g, 
    (100 + (g % 800)) || '.' || (100 + (g % 800)) || '.' || (100 + (g % 800)) || '-00'
FROM generate_series(0, 9999) AS g
WHERE NOT g = 1532 AND NOT g = 1755 AND NOT g = 1780 AND NOT g = 1888;
----------------------------------------------
INSERT INTO Taxi (Placa, Marca, Modelo, AnoFab, Licenca)
SELECT 
    'T' || g,
    CASE WHEN g % 2 = 0 THEN 'Ford' ELSE 'Wolkswagen' END,
    CASE WHEN g % 2 = 0 THEN 'Fiesta' ELSE 'Gol' END,
    2000 + (RANDOM() * 20)::INT,
    'LIC' || g
FROM generate_series(100000, 109999) AS g;
----------------------------------------------
INSERT INTO Corrida (CliId, Placa, DataPedido, Valor)
SELECT 
    '' || g,
    'T' || (g + 100000),
    DATE '2020-01-01' + (RANDOM() * 1825)::INT, 
    ROUND((RANDOM() * 1000)::NUMERIC, 2) 
FROM generate_series(0, 9999) AS g
WHERE NOT g = 1532 AND NOT g = 1755 AND NOT g = 1780 AND NOT g = 1888;


----------------------------------------------
EXPLAIN ANALYZE
SELECT 
    t.Marca, 
    t.Modelo, 
    COUNT(c.Placa) AS TotalCorridas,
    SUM(c.Valor) AS ReceitaTotal
FROM Taxi t
INNER JOIN Corrida c ON t.Placa = c.Placa
WHERE t.AnoFab < 2010 
  AND c.Valor > 20.00
GROUP BY t.Marca, t.Modelo
ORDER BY ReceitaTotal DESC;

----------------------------------------------
explain ANALYSE
SELECT 
    cl.Nome, 
    cl.CPF, 
    COUNT(c.Placa) AS QtdCorridas, 
    SUM(c.Valor) AS GastoTotalCliente
FROM Cliente cl
JOIN Corrida c ON cl.CliId = c.CliId
GROUP BY cl.Nome, cl.CPF
HAVING SUM(c.Valor) > (
    -- Subconsulta para calcular a média de gastos por cliente
    SELECT AVG(SomaPorCliente) 
    FROM (
        SELECT SUM(Valor) AS SomaPorCliente 
        FROM Corrida 
        GROUP BY CliId
    ) AS SubMedias
)
ORDER BY GastoTotalCliente DESC;

---------------------------------------------

explain ANALYSE
SELECT 
    cl.Nome, 
    cl.CPF, 
    t.Marca, 
    t.Modelo, 
    c.DataPedido, 
    c.Valor
FROM Cliente cl
JOIN Corrida c ON cl.CliId = c.CliId
JOIN Taxi t ON c.Placa = t.Placa
WHERE c.DataPedido = (
    -- Subconsulta correlacionada: busca a data máxima para o cliente atual
    SELECT MAX(c2.DataPedido)
    FROM Corrida c2
    WHERE c2.CliId = cl.CliId
)
AND c.Valor > 50.00
ORDER BY c.DataPedido DESC, c.Valor DESC;

-------------------------------------------------------------

explain ANALYSE
SELECT 
    EXTRACT(YEAR FROM c.DataPedido) AS AnoReferencia,
    t.Marca,
    COUNT(c.CliId) AS VolumeCorridas,
    ROUND(AVG(c.Valor), 2) AS TicketMedio,
    MAX(c.Valor) AS CorridaMaisCara
FROM Taxi t
INNER JOIN Corrida c ON t.Placa = c.Placa
GROUP BY EXTRACT(YEAR FROM c.DataPedido), t.Marca
HAVING COUNT(c.CliId) > 50
ORDER BY AnoReferencia DESC, VolumeCorridas DESC;

------------------------------------------------------------

explain ANALYSE
SELECT 
    cl.Nome, 
    COUNT(c.DataPedido) AS Frequencia,
    ROUND(AVG(c.Valor), 2) AS GastoMedio
FROM Cliente cl
JOIN Corrida c ON cl.CliId = c.CliId
WHERE c.Placa IN (
    -- Subconsulta que filtra as placas de modelos específicos
    SELECT Placa 
    FROM Taxi 
    WHERE Modelo IN ('Gol', 'Fiesta')
)
GROUP BY cl.Nome
HAVING COUNT(c.DataPedido) > 3
ORDER BY GastoMedio DESC;