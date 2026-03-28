import java.util.Scanner;
public class vogais {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        String frase = "";
        int a = 0, e = 0, i = 0, o = 0, u = 0;
        do {
            frase = scanner.nextLine();
            for (int j = 0; j < frase.length(); j++) {
                char c = Character.toLowerCase(frase.charAt(j));
                if (c == 'a') {
                    a++;
                }
                if (c == 'e') {
                    e++;
                }
                if (c == 'i') {
                    i++;
                }
                if (c == 'o') {
                    o++;
                }
                if (c == 'u') {
                    u++;
                }
            }
        } while (!frase.equals("FIM"));
        System.out.println("a=" + a);
        System.out.println("e=" + e);
        System.out.println("i=" + i);
        System.out.println("o=" + o);
        System.out.println("u=" + u);
        scanner.close();
    }
}