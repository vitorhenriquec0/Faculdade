package POO.Aulas.Aula4.entities2;

import POO.Aulas.Aula4.entities2.Pessoa;
import java.util.ArrayList;

public class Aluno extends Pessoa {

    private static final int TOTAL_HORARIOS = 4;
    private static final int TOTAL_DIAS = 5;
    private static final int MAX_DISCIPLINAS_SEMESTRE = 7;

    private Double media;
    private ArrayList<Disciplina> disciplinasInscritas = new ArrayList<>();

    private final int[][] horarios = {
            { 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0},
            { 0, 0, 0, 0, 0}
    };

    public Aluno(String nome, int idade, char sexo, int faltas, Double media) {
        super(nome, idade, sexo, faltas);
        this.media = media;
    }

    public void alterarMedia(Double media) {
        this.media = media;
    }

    public Double getMedia() {
        return media;
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

    public boolean inscreverDisciplina(Disciplina disciplina) {
        if (disciplinasInscritas.size() >= MAX_DISCIPLINAS_SEMESTRE) {
            System.out.println("Limite de disciplinas atingido (maximo 7 por semestre).");
            return false;
        }

        for (Disciplina.HorarioAula horarioAula : disciplina.getHorariosAula()) {
            if (temConflitoHorario(horarioAula.getDia(), horarioAula.getHorario())) {
                System.out.println("Conflito! Ja existe disciplina em " + horarioAula.getDescricaoDia() + " no horario " + horarioAula.getHorario());
                return false;
            }
        }

        for (Disciplina.HorarioAula horarioAula : disciplina.getHorariosAula()) {
            agendarAula(horarioAula.getDia(), horarioAula.getHorario());
        }
        disciplinasInscritas.add(disciplina);
        return true;
    }

    public ArrayList<Disciplina> getDisciplinas() {
        return disciplinasInscritas;
    }

    public void exibirMatrizHoraria() {
        System.out.println("\n=== MATRIZ DE HORARIOS - " + this.getNome() + " ===");
        System.out.println("Horarios:      1=8h   2=10h   3=14h   4=16h");
        System.out.print("Dia\\Hor ");
        for (int h = 1; h <= 4; h++) {
            System.out.print("\t" + h);
        }
        System.out.println();
        for (int d = 1; d <= 5; d++) {
            Pessoa.DiasSemana diaSemana = Pessoa.DiasSemana.values()[d - 1];
            System.out.print(diaSemana.getDescricao() + "  ");
            for (int h = 0; h < 4; h++) {
                System.out.print("\t" + horarios[h][d - 1]);
            }
            System.out.println();
        }
    }
}
