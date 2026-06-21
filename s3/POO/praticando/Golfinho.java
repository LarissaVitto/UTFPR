public class Golfinho extends Animal implements Treinavel{
    public Golfinho(String nome) {
        super(nome);
    }
    @Override
    public void EmitirSom(){
        System.out.println("O golfinho estala: Click-click!");
    }
    @Override
    public void RealizarTruque() throws EnergiaInsuficienteException{
        if(NivelEnergia < 40){
            throw new EnergiaInsuficienteException("O golfinho " + this.nome + " está cansado demais para realizar o truque!");
        }else{
            NivelEnergia -= 40;
            System.out.println("O golfinho " + this.nome + " deu um salto acrobatico!");
        }
    }
} 