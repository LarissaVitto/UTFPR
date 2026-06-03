public class temperatura {
    public static String getTemperatura(double temperaturas[], int indice) {
        try {
            return "Temperatura[" + indice + "]: " + temperaturas[indice];

        } catch (Exception e) {
            return "Erro! Dados da exceção: " + e.getMessage();
        }
    }
}
