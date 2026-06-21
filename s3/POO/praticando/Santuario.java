import java.util.ArrayList;

public class Santuario {
    ArrayList<Animal> animais;

    public Santuario() {
        this.animais = new ArrayList<Animal>();
    }

    public void acolherAnimal(Animal animal){
        animais.add(animal);
        System.out.println("O animal " + animal.getNome() + " foi acolhido no santuário.");
    }

    public Animal buscarPorNome(String nome) throws AnimalNaoEncontradoException {
    for(Animal animal : animais){
        if(animal.getNome().equalsIgnoreCase(nome)){
            System.out.println("Animal encontrado: " + animal.getNome() + ", Nivel de energia " + animal.getNivelEnergia());
            return animal; 
        }
    }
    throw new AnimalNaoEncontradoException("Nenhum animal encontrado com o nome: " + nome);
}

    public void apresentarShow() throws EnergiaInsuficienteException{
        for(Animal animal : animais){
            animal.EmitirSom();
            try{
                if(animal instanceof Treinavel){
                    ((Treinavel) animal).RealizarTruque();
                }
            } catch (EnergiaInsuficienteException e) {
                System.out.println("Erro ao realizar truque: " + e.getMessage());
            }
        }
    }
}
