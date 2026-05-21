import java.util.ArrayList;

public class MinhaColecao {

    ArrayList<String> colecao;

    public MinhaColecao() {
        colecao = new ArrayList<>();
    }

    public void adicionar(String carro) {
        for (String c : colecao) {
            if (c.equals(carro)) {
                return;
            }
        }
        colecao.add(carro);
    }

    public void remover(String carro) {
        colecao.remove(carro);
    }

    public void imprimir() {
        if (colecao.isEmpty()) {
            System.out.println("Lista vazia!");
        } else {
            for (int i = 0; i < colecao.size(); i++) {
                System.out.println(i + 1 + "-" + colecao.get(i));
            }
        }
    }
}