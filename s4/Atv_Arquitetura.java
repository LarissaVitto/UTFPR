package s4;

interface CapazDeAssobiar{ //Interface
    void assobiar();
}


class Pessoa implements CapazDeAssobiar{ //classe 1
    @Override
    public void assobiar() {
        System.out.println("A pessoa esta assobiando!");
    }
}

class Passaro implements CapazDeAssobiar{ //classe 2
    @Override
    public void assobiar(){
        System.out.println("O passaro está assobiando!");
    }
}


class Apito{ //componente
    public void fazerAssobiar(CapazDeAssobiar objeto) {
        objeto.assobiar();
    }
}


public class Atv_Arquitetura{
    public static void main(String[] args){
        Apito apito = new Apito();
        Pessoa pessoa = new Pessoa();
        Passaro passaro = new Passaro();
        apito.fazerAssobiar(pessoa);
        apito.fazerAssobiar(passaro);
    }
}