//package lista 3.2;
import java.util.Scanner;
public class mediaAritmetica {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int vetor[] = new int[N];
        double soma = 0;
        for (int i = 0; i < N; i++) {
            vetor[i] = scanner.nextInt();
            soma += vetor[i];
        }
        double media = soma / N;
        System.out.printf("%.2f\n", media);
        for (int i = 0; i < N; i++) {
            if (vetor[i] > media) {
                System.out.println(vetor[i]);
            }
        }
        scanner.close();
    }
}