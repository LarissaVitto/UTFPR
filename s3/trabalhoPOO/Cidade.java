package trabalhoPOO;

public class Cidade {
    //atributos
    private String nome;
    private String UF;

    //construtor
    public Cidade(String nome, String uF) {
        this.nome = nome;
        UF = uF;
    }
    
    //Getters e Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getUF() {
        return UF;
    }

    public void setUF(String UF) {
        this.UF = UF;
    }

}
