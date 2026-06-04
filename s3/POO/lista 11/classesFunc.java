public class classesFunc {
    public class Professor implements Funcionario {
        private String nome;
        private double CH, salario;

        public Professor(String nome, double CH) {
            this.nome = nome;
            this.CH = CH;
        }

        @Override
        public String getNome() {
            return nome;
        }

        @Override
        public double getCH() {
            return CH;
        }

        @Override
        public double CalcularSalario() {
            return CH * 60;
        }
    }
    public class Estagiario implements Funcionario {
        private String nome;
        private double CH, salario;

        public Estagiario(String nome, double CH) {
            this.nome = nome;
            this.CH = CH;
        }

        @Override
        public String getNome() {
            return nome;
        }

        @Override
        public double getCH() {
            return CH;
        }

        @Override
        public double CalcularSalario() {
            return CH * 12.50;
        }
    }

    public class Tecnico implements Funcionario {
        private String nome;
        private double CH, salario;

        public Tecnico(String nome, double CH) {
            this.nome = nome;
            this.CH = CH;
        }

        @Override
        public String getNome() {
            return nome;
        }

        @Override
        public double getCH() {
            return CH;
        }

        @Override
        public double CalcularSalario() {
            return CH * 40;
        }
    }
}
