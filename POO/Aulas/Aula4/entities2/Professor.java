package POO.Aulas.Aula4.entities2;

import POO.Aulas.Aula4.entities2.Pessoa;

public class Professor extends Pessoa {

    private static final int TOTAL_HORARIOS = 4;
    private static final int TOTAL_DIAS = 5;

    private String pesquisa;
    private Double salario;

    private final int[][] horarios = {
            { 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0}
    };

    public Professor(String nome, int idade, char sexo, int faltas, String pesquisa, Double salario) {
        super(nome, idade, sexo, faltas);
        this.pesquisa = pesquisa;
        this.salario = salario;
    }

    public String getPesquisa() {
        return pesquisa;
    }

    public void aumentarSalario(Double amount) {
        this.salario += amount;
    }

    public Double getSalario() {
        return salario;
    }

    private void validarDiaEHorario(int dia, int horario) {
        if (dia < 1 || dia > TOTAL_DIAS) {
            System.out.println("Dia invalido. Use valores de 1 a 5.");
            return;
        }
        if (horario < 1 || horario > TOTAL_HORARIOS) {
            System.out.println("Horario invalido. Use valores de 1 a 4.");
            return;
        }
    }

    public boolean temConflitoHorario(int dia, int horario) {
        validarDiaEHorario(dia, horario);
        return horarios[horario - 1][dia - 1] == 1;
    }

    public boolean agendarAula(int dia, int horario) {
        if (temConflitoHorario(dia, horario)) {
            return false;
        }

        horarios[horario - 1][dia - 1] = 1;
        return true;
    }
}
