package cch.model;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(name = "Cidade")
public class Cidade {
    //Atributos
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String nome;
    private String UF;

    //Construtor
    public Cidade(String nome, String uF) {
        this.nome = nome;
        UF = uF;
    }
    
    public Cidade () {}
    
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
    
    public Long getId() {
        return id;
    }
    
    public void setId(long id) {
        this.id = id; //método criado para ser possível alterar o cadastro da cidade
    }

}
