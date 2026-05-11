package POO.Aulas.Aula4.entities;

public class Time {
    private String nome;
    private String sede;
    private int vitorias = 0;
    private int empates = 0;
    private int derrotas = 0;
    private int div;

    public Time(String nome, String sede, int div) {
        this.nome = nome;
        this.sede = sede;
        this.div = div;
    }

    public Time(String nome, String sede, int vitorias, int empates, int derrotas, int div) {
        this.nome = nome;
        this.sede = sede;
        this.vitorias = vitorias;
        this.empates = empates;
        this.derrotas = derrotas;
        this.div = div;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSede() {
        return sede;
    }

    public void setSede(String sede) {
        this.sede = sede;
    }

    public int getVitorias() {
        return vitorias;
    }

    public int getEmpates() {
        return empates;
    }

    public int getDerrotas() {
        return derrotas;
    }

    public int getDiv() {
        return div;
    }

    public void setDiv(int div) {
        this.div = div;
    }

    public void ganharJogo() {
        this.vitorias++;
    }

    public void perderJogo() {
        this.derrotas++;
    }

    public void empatarJogo() {
        this.empates++;
    }
}
