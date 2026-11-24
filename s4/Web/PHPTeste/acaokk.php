<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <title> Teste de Ações</title>
</head>

<body>
    <?php
        $nome = $_POST["nome"] ?? "-";
        $telefone = $_POST["telefone"] ?? "-";
        $email = $_POST["email"] ?? "-";

        $senha = $_POST["password"] ?? "-";
        $hash = password_hash($senha, PASSWORD_DEFAULT);

        echo "Seu nome é: " . $nome;
        echo ", seu telefone é: " . $telefone;
        echo " e seu email é: " . $email;

        echo "<br/>Hash da senha: "
        . htmlspecialchars($hash, ENT_QUOTES, "UTF-8");
    ?>
</body>

</html>