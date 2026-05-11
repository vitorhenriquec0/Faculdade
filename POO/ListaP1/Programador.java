package POO.ListaP1;

public class Programador extends Funcionario implements Bonificavel {

    public Programador (String nome, double salarioBase) {
        super(nome, salarioBase);
    }

    public double calcularBonus() {
        return this.salarioBase * 0.10;
    }

    public double calcularSalario() {
        return this.salarioBase + calcularBonus();
    }
    
}
