public abstract class Animal {
    protected String nome;
    protected int NivelEnergia;

    public String setNome(String nome){
        this.nome = nome;
        return nome;
    }    
    public String getNome(){
        return nome;
    }

    public int setNivelEnergia(int NivelEnergia){
        this.NivelEnergia = NivelEnergia;
        return NivelEnergia;
    }
    public int getNivelEnergia(){
        return NivelEnergia;
    }

    public Animal(String nome){ //construtor
        setNome(nome);
        setNivelEnergia(100);
    }

    public void Alimentar(){
        NivelEnergia += 30;
        System.out.println("O animal foi alimentado. O Nivel de energia subiu para " + NivelEnergia);
    }

    public abstract void EmitirSom();
}


