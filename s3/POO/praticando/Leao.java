public class Leao extends Animal{
    public Leao(String nome){
        super(nome);
    }
    @Override
    public void EmitirSom(){
        System.out.println("O leao ruge: Roooar!");
    }
}
