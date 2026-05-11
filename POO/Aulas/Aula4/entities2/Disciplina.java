package POO.Aulas.Aula4.entities2;

import POO.Aulas.Aula4.entities2.*;
import java.util.ArrayList;
import java.util.List;

public class Disciplina {

    public static class HorarioAula {
        private final int dia;
        private final int horario;

        public HorarioAula(int dia, int horario) {
            this.dia = dia;
            this.horario = horario;
        }

        public int getDia() {
            return dia;
        }

        public int getHorario() {
            return horario;
        }

        public String getDescricaoDia() {
            return Pessoa.DiasSemana.values()[dia - 1].getDescricao();
        }
    }

    private String nomeDisciplina;
    private String professorDisciplina;
    private int dia; // vai de 1 a 5
    private int horario; // de 1 a 4
    
    private ArrayList<Aluno> alunos = new ArrayList<>();
    private ArrayList<HorarioAula> horariosAula = new ArrayList<>();

    public Disciplina(String nomeDisciplina, String professorDisciplina, int dia, int horario) {
        this.nomeDisciplina = nomeDisciplina;
        this.professorDisciplina = professorDisciplina;
        adicionarHorarioAula(dia, horario);
    }

    private boolean horarioValido(int dia, int horario) {
        return dia >= 1 && dia <= 5 && horario >= 1 && horario <= 4;
    }

    public boolean adicionarHorarioAula(int dia, int horario) {
        if (!horarioValido(dia, horario)) {
            return false;
        }

        for (HorarioAula horarioAula : horariosAula) {
            if (horarioAula.getDia() == dia && horarioAula.getHorario() == horario) {
                return false;
            }
        }

        horariosAula.add(new HorarioAula(dia, horario));
        if (horariosAula.size() == 1) {
            this.dia = dia;
            this.horario = horario;
        }
        return true;
    }

    public String getNomeDisciplina() {
        return nomeDisciplina;
    }

    public void setNomeDisciplina(String nomeDisciplina) {
        this.nomeDisciplina = nomeDisciplina;
    }

    public String getProfessorDisciplina() {
        return professorDisciplina;
    }

    public void setProfessorDisciplina(String professorDisciplina) {
        this.professorDisciplina = professorDisciplina;
    }

    public String getDia() {
        if (horariosAula.isEmpty()) {
            return "Dia invalido";
        }

        switch (horariosAula.get(0).getDia()) {
            case 1:
                return "Segunda-Feira";
            case 2:
                return "Terca-Feira";
            case 3:
                return "Quarta-Feira";
            case 4:
                return "Quinta-Feira";
            case 5:
                return "Sexta-Feira";
            default:
                return "Dia invalido";
        }
    }

    public int getDiaNumero() {
        return horariosAula.isEmpty() ? dia : horariosAula.get(0).getDia();
    }


    public void setDia(int dia) {
        this.dia = dia;
    }

    public int getHorario() {
        return horariosAula.isEmpty() ? horario : horariosAula.get(0).getHorario();
    }

    public void setHorario(int horario) {
        this.horario = horario;
    }

    public List<HorarioAula> getHorariosAula() {
        return new ArrayList<>(horariosAula);
    }

    public boolean conflitaCom(Disciplina outra) {
        for (HorarioAula meuHorario : horariosAula) {
            for (HorarioAula horarioOutro : outra.getHorariosAula()) {
                if (meuHorario.getDia() == horarioOutro.getDia()
                        && meuHorario.getHorario() == horarioOutro.getHorario()) {
                    return true;
                }
            }
        }
        return false;
    }

    public String getDescricaoHorarios() {
        if (horariosAula.isEmpty()) {
            return "Sem horarios cadastrados";
        }

        StringBuilder descricao = new StringBuilder();
        for (int i = 0; i < horariosAula.size(); i++) {
            HorarioAula horarioAula = horariosAula.get(i);
            if (i > 0) {
                descricao.append(" | ");
            }
            descricao.append(horarioAula.getDescricaoDia()).append(" - ").append(horarioAula.getHorario()).append("h");
        }
        return descricao.toString();
    }

    public boolean adicionarAluno(Aluno aluno) {
        if (aluno == null || alunos.contains(aluno)) {
            return false;
        }

        if (!aluno.inscreverDisciplina(this)) {
            return false;
        }

        alunos.add(aluno);
        return true;
    }

    public List<Aluno> getAlunos() {
        return new ArrayList<>(alunos);
    }

    
    
}
