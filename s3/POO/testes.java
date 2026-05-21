class Aluno{
    String nome;
    int idade;
    char genero;
    long ra;
    
    public Aluno(){
        nome = "Aluno";
        idade = 18;
        genero = 'M';
        ra = 123456789;
    }
    public Aluno(String nome, int idade){
        this.nome = "nome";
        this.idade = 18;
    }
    public Aluno(String nome, char genero, long ra){
        this.nome = nome;
        this.genero = genero;
        this.ra = ra;
        this.idade = 18;
    }
    public Aluno(String nomee, int idade){
        this.nome = nomee;
        genero = 'M';
        ra = 123456789;
        this.idade = idade;
    }
    public void print(){
        System.out.println(nome + " - " + idade + " - " + genero  + " - " + ra);    }
}