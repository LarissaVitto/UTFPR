//package lista 3.2;
import java.util.Scanner;
public class fraseInvertida {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        String frase = scanner.nextLine();
        String invertida = "";
        for (int i = frase.length() - 1; i >= 0; i--) {
            invertida += frase.charAt(i);
        }
        System.out.println(invertida);
        System.out.println(frase.length());
        scanner.close();
    }
}
