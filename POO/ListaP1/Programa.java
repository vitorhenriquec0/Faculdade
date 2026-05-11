package POO.ListaP1;

import java.util.ArrayList;

public class Programa {
    public static void main(String[] args) {
        ArrayList<Funcionario> funcionarios = new ArrayList<>();

        funcionarios.add(new Gerente("Vitor", 23000));
        funcionarios.add(new Programador("Mari Roussef, Galocha, Julio", 65));
        funcionarios.add(new Programador("Heitor, Laura e Arthur", 40));
        funcionarios.add(new Programador("Vitoria, Beatriz, Dan", 50));

        for (Funcionario f : funcionarios) {
            double valorBonus = 0.0;

            if (f instanceof Bonificavel) {
                valorBonus = ((Bonificavel) f).calcularBonus();
            }

            System.out.println("Nome: " + f.getNome());
            System.out.println("Valor do Bônus: R$ " + valorBonus);
            System.out.println("Salário: R$ " + f.calcularSalario());
            System.out.println();
        }
    }
}
