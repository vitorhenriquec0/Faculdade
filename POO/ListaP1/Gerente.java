package POO.ListaP1;

public class Gerente extends Funcionario implements Bonificavel {

    public Gerente(String nome, double salarioBase) {
        super(nome, salarioBase);
    }

    public double calcularBonus() {
        return this.salarioBase * 0.20;
    }

    public double calcularSalario() {
        return this.salarioBase + calcularBonus();
    }
    
}
