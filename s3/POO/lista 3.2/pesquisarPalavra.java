import java.util.Scanner;
public class pesquisarPalavra {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        String frase = scanner.nextLine();
        String palavra = scanner.nextLine();
        int pesquisa = 0;
        for (int i = 0; i <= frase.length() - palavra.length(); i++) {
            boolean igual = true;
            for (int j = 0; j < palavra.length(); j++) {
                if (frase.charAt(i + j) != palavra.charAt(j)) {
                    igual = false;
                    break;
                }
            }
            if (igual) {
                pesquisa++;
            }
        }
        System.out.println(palavra + "=" + pesquisa);
        scanner.close();
    }
}