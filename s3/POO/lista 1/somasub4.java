//import java.util.Scanner;
public class somasub4 {
    public static void main(String args[]) {
        java.util.Scanner entrada = new java.util.Scanner(System.in);
        int numero = entrada.nextInt();
        int numero2 = entrada.nextInt();
        System.out.println("soma = " + (numero + numero2) + "\nsubtracao = " + (numero - numero2));
        entrada.close();
    }
}