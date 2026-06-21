**Código gerado a partir de uma proposta de exercício sugerida pela IA Gemini para estudo para a segunda prova de POO.**

Proposta:
Aqui está uma proposta de exercício ao nível de uma prova prática, focada num **Santuário de Animais**, que exige a integração de todos os quatro conceitos.

---

### 🐾 Exercício Prático: Sistema de Gestão de um Santuário de Animais

**Objetivo:** Desenvolver uma aplicação em Java para gerir os animais de um santuário ecológico, aplicando Classes Abstratas, Interfaces, Tratamento de Exceções e Coleções (`ArrayList`).

#### Cenário e Requisitos:

**1. Interfaces (Baseado na Aula 12)**

* Crie uma interface chamada `Treinavel`.
* Esta interface deve conter o método `void realizarTruque()`.

**2. Classes Abstratas (Baseado na Aula 11)**

* Crie uma classe abstrata chamada `Animal`.
* Deve conter os atributos protegidos (ou privados com *getters/setters*): `nome` (String) e `nivelEnergia` (int).
* Crie um construtor que receba o `nome` e defina o `nivelEnergia` inicial como 100.
* Crie um método concreto `void alimentar()` que aumenta o `nivelEnergia` em 30 pontos.
* Crie um **método abstrato** `void emitirSom()`.

**3. Tratamento de Exceções (Baseado na Aula 13)**

* Crie uma exceção personalizada chamada `AnimalNaoEncontradoException` (que herde de `Exception`).
* Crie uma exceção personalizada chamada `EnergiaInsuficienteException` (que herde de `Exception`). Esta exceção deve ser lançada quando um animal tenta fazer um esforço mas está demasiado cansado.

**4. Classes Concretas e Herança**

* Crie a classe `Leao` que herda de `Animal`.
* Implemente o método `emitirSom()`, que deve imprimir no ecrã: *"O leão ruge: Roooar!"*


* Crie a classe `Golfinho` que herda de `Animal` e implementa a interface `Treinavel`.
* Implemente o método `emitirSom()`, imprimindo: *"O golfinho estala: Click-click!"*
* **Regra do Truque:** No método `realizarTruque()`, verifique se o `nivelEnergia` é inferior a 40. Se for, lance a `EnergiaInsuficienteException`. Caso contrário, diminua a energia em 40 pontos e imprima *"O golfinho [nome] deu um salto acrobático!"*.



**5. Coleções (Baseado na Aula 14)**

* Crie uma classe chamada `Santuario`.
* Deve possuir um atributo `animais` que é um `ArrayList` do tipo `Animal`.
* Implemente os seguintes métodos:
1. `void acolherAnimal(Animal a)`: Adiciona o animal à coleção.
2. `Animal buscarPorNome(String nome)`: Percorre a lista. Se encontrar o animal com esse exato nome, devolve-o. Se chegar ao fim da lista sem o encontrar, lança a `AnimalNaoEncontradoException`.
3. `void apresentarShow()`: Percorre todos os animais da lista. Para cada animal, mande-o `emitirSom()`. Depois, verifique se o animal é capaz de realizar truques (usando o operador `instanceof` com a interface `Treinavel`). Se for treinável, chame o método `realizarTruque()`.


* **Atenção:** Deve colocar a chamada do truque dentro de um bloco `try... catch` para capturar a `EnergiaInsuficienteException`. Se o animal não tiver energia, capture a exceção e imprima *"O animal está demasiado cansado para atuar hoje."*, sem deixar o programa ir abaixo.



---

#### 🚀 Classe Principal (Main) para Testes

Crie uma classe `Main` para simular o funcionamento do sistema com o seguinte guião:

1. Instancie um objeto `Santuario`.
2. Crie um objeto `Leao` chamado "Simba".
3. Crie um objeto `Golfinho` chamado "Flipper".
4. Adicione ambos ao santuário.
5. Invoque o método `buscarPorNome` procurando por "Dumbo". Capture a exceção que será gerada e imprima a mensagem de erro de forma amigável no ecrã.
6. Chame o método `apresentarShow()` do santuário pela primeira vez (o Flipper deverá saltar e gastar energia).
7. Chame o método `apresentarShow()` uma segunda e terceira vez consecutivas (para forçar o esgotamento da energia do Flipper e testar se a mensagem do bloco `catch` é exibida corretamente).
8. Encontre o Flipper usando o método `buscarPorNome`, chame o método `alimentar()` para restaurar a sua energia, e chame o `apresentarShow()` mais uma vez.

---

### Dicas para resolução:

* **Polimorfismo:** Repare que o santuário trata todos como `Animal`. O método `emitirSom()` comportar-se-á de maneira diferente para leões e golfinhos, de forma automática.
* **Casting:** No método `apresentarShow()`, quando confirmar que o animal `instanceof Treinavel`, terá de fazer o *cast* (conversão de tipo) antes de chamar o método do truque. Exemplo: `((Treinavel) animalAtual).realizarTruque();`



**Avaliação Final:**
Excelente trabalho! O seu código está muito bem estruturado e demonstra uma compreensão sólida dos quatro pilares testados: Classes Abstratas, Interfaces, Tratamento de Exceções e Coleções. Você conseguiu integrar todos os conceitos de forma funcional e lógica.

Aqui está uma avaliação detalhada da sua implementação:

### 🌟 Pontos Fortes e Acertos

* **Estrutura de Herança e Interfaces:** A hierarquia está perfeita. A classe abstrata `Animal` aplica corretamente os atributos protegidos e divide bem a responsabilidade entre métodos concretos (como `Alimentar()`) e abstratos (como `EmitirSom()`). O uso da interface `Treinavel` pela classe `Golfinho` foi muito bem aplicado.


* **Tratamento de Exceções (Checked Exceptions):** Você criou corretamente as exceções `AnimalNaoEncontradoException` e `EnergiaInsuficienteException` herdando de `Exception`. A lógica de lançamento com `throw new` dentro dos métodos está precisa.


* **Manipulação de Coleções e Polimorfismo:** Na classe `Santuario`, o uso do `ArrayList` para armazenar objetos do tipo `Animal` está correto. O uso do operador `instanceof` seguido pelo *casting* seguro `((Treinavel) animal)` foi implementado com perfeição, permitindo tratar comportamentos específicos em uma lista genérica.


* **Busca Flexível:** No método `buscarPorNome`, você utilizou `equalsIgnoreCase`. Embora o exercício pedisse o "exato nome", usar ignorar maiúsculas/minúsculas é considerado uma boa prática em buscas de *strings* do mundo real.



---

### 🛠️ Pontos de Atenção e Sugeridas Melhorias

Para deixar o seu código com nível profissional e totalmente aderente ao roteiro original, preste atenção aos seguintes detalhes:

* **Convenções de Nomenclatura (CamelCase):** Em Java, é um padrão forte na comunidade que **nomes de variáveis e métodos** comecem com letra minúscula (ex: `nivelEnergia`, `alimentar()`, `emitirSom()`, `realizarTruque()`). No seu código, você usou iniciais maiúsculas em vários desses elementos, como `NivelEnergia` e `Alimentar()` na classe `Animal`, e `RealizarTruque()` na interface `Treinavel`. Lembre-se: apenas Classes e Interfaces devem começar com letra maiúscula (PascalCase).


* **Cláusula `throws` Redundante:** Na classe `Santuario`, a assinatura do método possui `public void apresentarShow() throws EnergiaInsuficienteException`. Como você já envelopou a chamada do truque em um bloco `try...catch` capturando essa exata exceção dentro do próprio método, ela nunca será propagada para fora. Portanto, a declaração `throws` na assinatura do método é desnecessária.


* **Fidelidade ao Roteiro na classe `Main`:**
* O roteiro pedia para esgotar a energia do Flipper chamando o método `apresentarShow()` três vezes consecutivas. Na sua implementação, você optou por um atalho, forçando a energia do animal diretamente com `golfinho1.setNivelEnergia(30);`. Embora isso sirva para testar a exceção, ignora a lógica de simulação proposta.


* No bloco `catch` do método `apresentarShow()`, o exercício solicitava a impressão estática: *"O animal está demasiado cansado para atuar hoje."*. Você optou por `"Erro ao realizar truque: " + e.getMessage()`. Tecnologicamente não há erro, mas em avaliações estritas, fugir do texto exato solicitado pode custar alguns décimos.





### Veredito

**Nota:** 9.0 / 10.
Você dominou a parte lógica e de arquitetura Orientada a Objetos. As correções apontadas são apenas refinamentos de convenção de código (boas práticas de mercado) e pequenos desvios do roteiro de testes.
