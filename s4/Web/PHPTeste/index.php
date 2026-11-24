<!DOCTYPE html>
<html lang="pt-br">

<head>
    <meta charset="UTF-8">
    <title> Teste de PHP</title>
</head>

<body>
    <form action="acaokk.php" method="post">
        <label for="nome">Nome Post:</label>
        <input type="text" name="nome" id="nome" required>
        <br/>
        <label for="email">Email Post:</label>
        <input type="email" name="email" id="email" required>
        <br/>
        <label for="telefone">Telefone Post:</label>
        <input type="tel" name="telefone" id="telefone" required>
        <br/>
        <label for="password">Senha Post:</label>
        <input type="password" name="password" id="password" required>
        <input type="submit" value="Enviar">
    </form>
    <br/>
    <br/>
    <br/>
    <form action="acao.php" method="get">
        <label for="nome">Nome Get:</label>
        <input type="text" name="nome" id="nome" required>
        <br/>
        <label for="idade">Idade Get:</label>
        <input type="number" name="idade" id="idade" required>
        <br/>
        <input type="submit" value="Enviar">

    </form>

    <?php
        echo "<h1> Teste de PHP </h1>";
        $nota = 10.00;
        
        echo "Nota: $nota";


        if ($nota >= 7) {
            echo "<br/>Aprovado";
        } else {
            echo "<p> Reprovado </p>";
        }

        $N = 5;
        for($i = 0; $i < 10; $i++) {
            echo "<br/> $i x $N = " . ($i * $N);
        }

        $a = ["Maçã", "Laranja", 1];
        foreach($a as $item) {
            echo "<br/>" . $item;
        }
        echo"<br\>" .$a[0];
        

        $dic= ["fruta-a" => "Maçã", 
                "fruta-b" => "Laranja",
                "Limão"];

        echo"<p> Fruta A: " . $dic["fruta-a"] . "</p>";
        echo "<br/>" . var_dump($dic);
    ?>
</body>

</html>