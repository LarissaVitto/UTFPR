package lista2;
//import java.util.Scanner;


public class somandoatenegativo6 {
    public static void main(String args[]) {
            java.util.Scanner entrada = new java.util.Scanner(System.in);
            int numero = 0, quantidade = 0;
            while (true) {
                numero += entrada.nextInt();
                quantidade++;
                if (numero < 0) {
                    break;
                }
            }
            System.out.println("Quantidade = " + quantidade + "\nSoma = " + numero);
            entrada.close();
    }
}
