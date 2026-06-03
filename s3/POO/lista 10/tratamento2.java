import java.util.Scanner;

public class tratamento2{
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        int x = 0;
        double soma = 0;

        for (int i = 0; i < 10; i++) {

            try {
                double valor = entrada.nextDouble();

                soma += valor;
                x++;

            } catch (Exception e) {
                entrada.next(); 
            }
        }
        double y = soma / 10;
        System.out.printf("Entradas aceitas: %d, média: %.2f", x, y);
        entrada.close();
    }
}