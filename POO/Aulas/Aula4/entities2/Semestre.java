package POO.Aulas.Aula4.entities2;

import POO.Aulas.Aula4.entities2.*;
import java.util.ArrayList;
import java.util.List;

public class Semestre {
    
    private String periodo;
    private ArrayList<Disciplina> disciplinas;
    private ArrayList<Aluno> alunosPeriodo;

    public Semestre(String periodo) {
        this.periodo = periodo;
        this.disciplinas = new ArrayList<>();
        this.alunosPeriodo = new ArrayList<>();
    }

    public String getPeriodo() {
        return periodo;
    }

    public void setPeriodo(String periodo) {
        this.periodo = periodo;
    }

    public boolean adicionarDisciplina(Disciplina disciplina) {
        if (disciplina == null || disciplinas.contains(disciplina)) {
            return false;
        }

        for (Disciplina d : disciplinas) {
            if (d.conflitaCom(disciplina)) {
                System.out.println("Conflito de horario: " + disciplina.getNomeDisciplina() + " conflita com " + d.getNomeDisciplina());
                return false;
            }
        }

        disciplinas.add(disciplina);
        System.out.println("Disciplina " + disciplina.getNomeDisciplina() + " adicionada ao semestre " + periodo);
        return true;
    }

    public void removerDisciplina(Disciplina disciplina) {
        if (disciplinas.remove(disciplina)) {
            System.out.println("Disciplina " + disciplina.getNomeDisciplina() + " removida do semestre " + periodo);
        }
    }

    public List<Disciplina> listarDisciplinas() {
        return new ArrayList<>(disciplinas);
    }

    public boolean contemDisciplina(Disciplina disciplina) {
        return disciplinas.contains(disciplina);
    }

    public boolean horarioDisponivel(int dia, int horario) {
        for (Disciplina disciplina : disciplinas) {
            for (Disciplina.HorarioAula horarioAula : disciplina.getHorariosAula()) {
                if (horarioAula.getDia() == dia && horarioAula.getHorario() == horario) {
                    return false;
                }
            }
        }

        return true;
    }

    public boolean matricularAlunoEmDisciplina(Aluno aluno, Disciplina disciplina) {
        if (aluno == null || disciplina == null) {
            return false;
        }

        if (!contemDisciplina(disciplina)) {
            System.out.println("Disciplina " + disciplina.getNomeDisciplina() + " nao pertence ao semestre " + periodo);
            return false;
        }

        if (!disciplina.adicionarAluno(aluno)) {
            System.out.println("Nao foi possivel matricular " + aluno.getNome() + " em " + disciplina.getNomeDisciplina());
            return false;
        }

        if (!alunosPeriodo.contains(aluno)) {
            alunosPeriodo.add(aluno);
        }

        System.out.println("Aluno " + aluno.getNome() + " matriculado em " + disciplina.getNomeDisciplina());
        return true;
    }

    public List<Aluno> listarAlunosPeriodo() {
        return new ArrayList<>(alunosPeriodo);
    }

    public void exibirAlunosPeriodo() {
        System.out.println("=== Alunos do Semestre " + periodo + " ===");
        if (alunosPeriodo.isEmpty()) {
            System.out.println("Nenhum aluno matriculado.");
            return;
        }

        for (Aluno aluno : alunosPeriodo) {
            System.out.println("- " + aluno.getNome() + " | Disciplinas: " + aluno.getDisciplinas().size());
        }
    }

    public Disciplina buscarDisciplinaPorNome(String nome) {
        for (Disciplina d : disciplinas) {
            if (d.getNomeDisciplina().equalsIgnoreCase(nome)) {
                return d;
            }
        }
        return null;
    }

    public void exibirDisciplinas() {
        System.out.println("=== Disciplinas do Semestre " + periodo + " ===");
        if (disciplinas.isEmpty()) {
            System.out.println("Nenhuma disciplina cadastrada.");
        } else {
            for (Disciplina d : disciplinas) {
                System.out.println("- " + d.getNomeDisciplina() + " | Prof: " + d.getProfessorDisciplina() 
                    + " | Horarios: " + d.getDescricaoHorarios());
            }
        }
    }
}
