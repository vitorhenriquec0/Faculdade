package POO.Aulas.Aula6.Artigo;

public class Congresso extends Artigo {
    private String país;

    public Congresso(String nome, String autor, String título, int ano, String país) {
        super(nome, autor, título, ano);
        this.país = país;
    }

    public String getPaís() {
        return país;
    }

    public void setPaís(String país) {
        this.país = país;
    }
}
