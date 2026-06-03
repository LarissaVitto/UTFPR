import java.util.Scanner;
public class tratamento {
    public static void main(String [] args){
         Scanner entrada = new Scanner(System.in);
        try{
            int r = entrada.nextInt();
            System.out.println(r * 2);
        } catch (Exception e) {
            System.out.println("Entrada Incorreta: informe somente inteiros.");
        }
    }  
}