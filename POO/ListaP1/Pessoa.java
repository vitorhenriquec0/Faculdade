package POO.ListaP1;

public class Pessoa {
    private String nome;
    private Pessoa pai;
    private Pessoa mae;

    public Pessoa(String nome, Pessoa pai, Pessoa mae) {
        this.nome = nome;
        this.pai = pai;
        this.mae = mae;
    }

    public Pessoa(String nome) {
        this.nome = nome;
        this.pai = null;
        this.mae = null;
    }

    public boolean samePerson(Pessoa outra) {
        if (outra == null) return false;
        if (this.nome.equals(outra.getNome()) && this.mae.equals(outra.mae)) {
            return true;
        }
        return false;
    }

    public boolean areSisters(Pessoa outra) {
        if (outra == null) return false;
        if (this == outra) return false;

        boolean mesmaMae = this.mae != null && this.mae.equals(outra.mae);
        boolean mesmoPai = this.pai != null && this.pai.equals(outra.pai);

        return mesmaMae && mesmoPai;
    }

    public boolean antecessor(Pessoa outra) {
        if (outra == null) return false;

        if (this.pai != null && this.pai.equals(outra)) return true;
        if (this.mae != null && this.mae.equals(outra)) return true;

        boolean ladoMae = false;
        if (this.mae != null) ladoMae = this.mae.antecessor(outra);

        boolean ladoPai = false;
        if (this.pai != null) ladoPai = this.pai.antecessor(outra);

        return ladoMae || ladoPai;
    }

    public String getNome() {
        return nome;
    }
}
