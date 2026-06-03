public class interfaceUm {
    public static void main(String[] args) {
        public class MinhaClasse implements MinhaInterface{
            String minhaFrase = getFrase();
            public void concatenar(String s){
                minhaFrase += s;
                setFrase(minhaFrase);
            }
            public int tamanho(){
                String minhaFrase = getFrase();
                return minhaFrase.length();
            }
            public String getFrase(){
                return minhaFrase;
            }
            public void setFrase(String str){
                this.minhaFrase = str;
            }
        }
    }
}