import java.util.Scanner;
public class interseção {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int tam = scanner.nextInt();
        int vet1[] = new int[tam];
        int vet2[] = new int[tam];
        for (int i = 0; i < tam; i++) {
            vet1[i] = scanner.nextInt();
        }
        for (int i = 0; i < tam; i++) {
            vet2[i] = scanner.nextInt();
        }   
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                if (vet1[i] == vet2[j]) {
                    System.out.println(vet1[i]);
                }
            }
        }
        scanner.close();
    }
}