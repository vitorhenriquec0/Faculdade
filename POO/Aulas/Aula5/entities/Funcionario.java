package POO.Aulas.Aula5.entities;

import java.time.LocalDate;

public class Funcionario extends Pessoa {

    private LocalDate admissao;
    private double salario;

    public Funcionario(String nome, int identidade, LocalDate nascimento, LocalDate admissao, double salario) {
        super(nome, identidade, nascimento);
        this.admissao = admissao;
        this.salario = salario;
    }

    public String toString() {
        return super.toString()
                + "\nAdmissão: " + formatarData(this.admissao)
                + "\nSalário: " + this.salario;
    }

    public Double getSalario() {
        return salario;
    }
}
