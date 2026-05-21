import java.util.ArrayList;

public class Loja {
    
    private ArrayList<Produto> listaDeProdutos;

    public Loja() {
        listaDeProdutos = new ArrayList<>();
    }

    public void adicionar(Produto p){
        listaDeProdutos.add(p);
    }

    public Produto getProdutoMaisCaro(){
        if (listaDeProdutos.isEmpty()) {
            return null; 
        }
        
        Produto maisCaro = listaDeProdutos.get(0);
        for(Produto p : listaDeProdutos){
            if(p.getPreco() > maisCaro.getPreco()){
                maisCaro = p; 
            }
        }
        return maisCaro;
    }

    public Produto getProdutoMenosCaro(){
        if (listaDeProdutos.isEmpty()) {
            return null; 
        }
        
        Produto menosCaro = listaDeProdutos.get(0);
        for(Produto p : listaDeProdutos){
            if(p.getPreco() < menosCaro.getPreco()){
                menosCaro = p; 
            }
        }
        return menosCaro;
    }
}