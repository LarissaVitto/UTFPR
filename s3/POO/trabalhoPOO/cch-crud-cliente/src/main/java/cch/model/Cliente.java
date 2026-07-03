package cch.model;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.Table;
import jakarta.persistence.JoinColumn;

@Entity
@Table(name = "Cliente")
public class Cliente{
    //atributos
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private String nome;
    private String cpf;
    private String telefone;
    private String email;
    
    @ManyToOne
    @JoinColumn(name = "Id_Cidade")
    private Cidade cidade;
        
    //construtor
    public Cliente(String nome, String cpf, String telefone, Cidade cidade, String email) {
        this.nome = nome;
        this.cpf = cpf;
        this.telefone = telefone;
        this.cidade = cidade;
        this.email = email;
    }
    public Cliente() {} // Construtor vazio criado para ser possível alterar o cadastro do cliente
    
    //Getters e Setters
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public String getCpf() {
        return cpf;
    }
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    
    public String getTelefone() {
        return telefone;
    }
    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    
    public Cidade getCidade() {
        return cidade;
    }
    public void setCidade(Cidade cidade) {
        this.cidade = cidade;
    }
    
    public Long getId(){
        return id;
    }
    public void setId(long id) {
        this.id = id; //método criado para ser possível alterar o cadastro do cliente
    }
    public String getEmail(){
        return email;
    }
    public void setEmail(String email){
        this.email = email;
    }
}
