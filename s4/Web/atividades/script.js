// Q-03: Calculando a média de um estudante
let nota1 = 9.5;
let nota2 = 7;

let media = (nota1 + nota2) / 2;

document.getElementById("notas").textContent = ("Notas utilizadas: Nota 1: " + nota1 + " e Nota 2: " + nota2);

if (media >= 6) {
    document.getElementById("Q-03").textContent = "Média: " + media + " - Aprovado!";
} else {
    document.getElementById("Q-03").textContent = "Média: " + media + " - Reprovado!";
}

// Q-04: Classificando uma faixa etária
let idade = 20;

document.getElementById("idade").textContent = ("Idade utilizada: " + idade);

if (idade < 12) {
    document.getElementById("Q-04").textContent = "Idade: " + idade + " - Criança (até 11 anos)";
} else if (idade >= 12 && idade <= 17) {
    document.getElementById("Q-04").textContent = "Idade: " + idade + " - Adolescente (de 12 a 17 anos)";
} else if (idade >= 18 && idade <= 59) {
    document.getElementById("Q-04").textContent = "Idade: " + idade + " - Adulto (de 18 a 59 anos)";
} else {
    document.getElementById("Q-04").textContent = "Idade: " + idade + " - Idoso (60 anos ou mais)";
}

// Q-13: Gerando um relatório de notas
let matNotas = [[7.5, 8.0, 6.5, 9.0], [5.0, 7.0, 8.5, 6.0], [9.5, 8.5, 7.5, 8.0]];
let totalNotas = 0;
let maior = 0;

let mat = "";  //Não consegui pular linha :!


for (let i = 0; i < matNotas.length; i++) { 
    for (let j = 0; j < matNotas[i].length; j++) {
        mat += matNotas[i][j] + " ";
        if(matNotas[i][j] >= maior) {
            maior = matNotas[i][j];
        }
    }
}

document.getElementById("matriz").textContent = mat;

let situacoes = ""; //Não consegui pular linha :!

for (let i = 0; i < matNotas.length; i++) {
    for (let j = 0; j < matNotas[i].length; j++) {
        
        if (matNotas[i][j] >= 6) {
            situacoes += "Nota: " + matNotas[i][j] + " - Aprovado!\n";
        } else {
            situacoes += "Nota: " + matNotas[i][j] + " - Reprovado!\n";
        }
        totalNotas += matNotas[i][j];
    }
}

function calcularMedia() {
    return totalNotas / (matNotas.length * matNotas[0].length);
}


document.getElementById("situacao").textContent = situacoes;

document.getElementById("qtdTot").textContent = "Total de notas: " + totalNotas;

document.getElementById("mediaArit").textContent = "Média Aritmética: " + calcularMedia();

document.getElementById("maior").textContent = "Maior nota: " + maior;

// 2.10: Prática de integração
let contador = 0;

function adicionarItem() {
    contador++;
    const lista = document.getElementById("Lista");
    const novoItem = document.createElement("li");
    novoItem.textContent = "Novo Item " + contador;
    lista.appendChild(novoItem);
}

function removerItem() {
    const lista = document.getElementById("Lista");
    if (lista.lastElementChild) {
        lista.removeChild(lista.lastElementChild);
        contador--;
    }
}    