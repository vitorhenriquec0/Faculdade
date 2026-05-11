package POO.Aulas.Aula4.entities2;

import POO.Aulas.Aula4.entities2.Pessoa;

public class Funcionario extends Pessoa {

    private String cargo;
    private Double salario;

    public Funcionario(String nome, int idade, char sexo, int faltas, String cargo, Double salario) {
        super(nome, idade, sexo, faltas);
        this.cargo = cargo;
        this.salario = salario;
    }

    public String getCargo() {
        return cargo;
    }

    public void aumentarSalario(Double amount) {
        this.salario += amount;
    }

    public Double getSalario() {
        return salario;
    }
}
