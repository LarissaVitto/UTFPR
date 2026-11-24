<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <title> Teste de Ações</title>
</head>

<body>
    <?php
        $nome = $_GET["nome"] ?? "-";
        $idade = $_GET["idade"] ?? "-";

        echo "Seu nome é: " . $nome;
        echo " e sua idade é: " . $idade;
    ?>
</body>

</html>