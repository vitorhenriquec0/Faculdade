package POO.Aulas.Aula6.Artigo;

public class Revistas extends Artigo {
    private String editora;
    private int volume;

    public Revistas(String nome, String autor, String título, int ano, String editora, int volume) {
        super(nome, autor, título, ano);
        this.editora = editora;
        this.volume = volume;
    }

    public boolean remover() {
        if (this.ano < 2021) {
            return true;
        } else {
            return false;
        }
    }

    public String getEditora() {
        return editora;
    }

    public void setEditora(String editora) {
        this.editora = editora;
    }

    public int getVolume() {
        return volume;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    
}
