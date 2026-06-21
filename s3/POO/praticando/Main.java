public class Main {
    public static void main(String[] args) {
        Santuario s = new Santuario();

        Leao leao1 = new Leao("Simba");
        Golfinho golfinho1 = new Golfinho("Flipper");

        s.acolherAnimal(golfinho1);
        s.acolherAnimal(leao1);

        try {
            s.buscarPorNome("Simba");
            s.buscarPorNome("Flipper");
            s.buscarPorNome("Dumbo"); 
        } catch (AnimalNaoEncontradoException e) {
            System.out.println(e.getMessage());
        }
        
        golfinho1.setNivelEnergia(30);
        
        try{
            s.apresentarShow();
        } catch (EnergiaInsuficienteException e) {
            System.out.println("Erro ao apresentar show: " + e.getMessage());
        }


        try {
            Animal animalEncontrado = s.buscarPorNome("Flipper");
            animalEncontrado.Alimentar();
            
            System.out.println(animalEncontrado.getNome() + " foi alimentado e recuperou 30 de energia!");
            }
        catch (AnimalNaoEncontradoException e) {
                System.out.println("Falha ao alimentar: " + e.getMessage());
            }
        try{
            s.apresentarShow();
        } catch (EnergiaInsuficienteException e) {
            System.out.println("Erro ao apresentar show: " + e.getMessage());
        }
    }
}
