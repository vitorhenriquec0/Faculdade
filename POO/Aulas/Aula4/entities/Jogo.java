package POO.Aulas.Aula4.entities;

import POO.Aulas.Aula4.entities.Time;

public class Jogo {
    private Time mandante;
    private Time visitante;
    private String local;
    private int pm;
    private int pv;

    public Jogo() {

    }

    public Jogo CriarJogo(Time mandante, Time visitante) {
        if (mandante != visitante && mandante.getDiv() == visitante.getDiv()) {
            this.mandante = mandante;
            this.visitante = visitante;
            this.local = mandante.getSede();
            System.out.println("Jogo criado!");
            return this;
        } else {
            System.out.println("Jogo inválido!");
            return null;
        }
    }

    public Time getMandante() {
        return mandante;
    }

    public void setMandante(Time mandante) {
        this.mandante = mandante;
    }

    public Time getVisitante() {
        return visitante;
    }

    public void setVisitante(Time visitante) {
        this.visitante = visitante;
    }

    public String getLocal() {
        return local;
    }

    public void setLocal(String local) {
        this.local = local;
    }

    public int getPm() {
        return pm;
    }

    public void setPm(int pm) {
        this.pm = pm;
    }

    public int getPv() {
        return pv;
    }

    public void setPv(int pv) {
        this.pv = pv;
    }

    public void resultadoJogo(int pm, int pv) {
        this.pm = pm;
        this.pv = pv;
        if (pm > pv) {
            this.mandante.ganharJogo();
            this.visitante.perderJogo();
            System.out.println(this.mandante.getNome() + " venceu o jogo");
        } else if (pv > pm) {
            this.mandante.perderJogo();
            this.visitante.ganharJogo();
            System.out.println(this.visitante.getNome() + " venceu o jogo");
        } else {
            this.mandante.empatarJogo();
            this.visitante.empatarJogo();
            System.out.println("O jogo empatou");
        }
    }

}