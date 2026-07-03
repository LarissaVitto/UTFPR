package cch;
import cch.view.Principal;
public class Main {
    public static void main(String[] args) {
        java.awt.EventQueue.invokeLater(() -> {
            new Principal().setVisible(true);
        });    
    }
}
