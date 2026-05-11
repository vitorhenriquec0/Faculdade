package POO.Aulas.Aula5.entities;

import java.time.LocalDate;

import POO.Aulas.Aula5.entities.Funcionario;
import POO.Aulas.Aula5.entities.Pessoa;

public class Chefe extends Funcionario{

    private String departamento;
    private LocalDate promocao;

    public Chefe(String nome, int identidade, LocalDate nascimento, LocalDate admissao, double salario, String departamento, Date promocao) {
        super(nome, identidade, nascimento, admissao, salario);
        this.departamento = departamento;
        this.promocao = promocao;
    }

    public String toString() {
        return super.toString()
                + "\nDepartamento: " + this.departamento
                + "\nPromoção: " + formatarData(this.promocao);
    }

    public String getDepartamento() {
        return departamento;
    }
}
