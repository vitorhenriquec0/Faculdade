package POO.ListaP1;

import java.util.ArrayList;

public class Pais {
    private String ISO;
    private String nome;
    private int populacao;
    private double dimensao;
    private ArrayList<Pais> vizinhos = new ArrayList<>();

    public Pais(String ISO, String nome, int populacao, double dimensao) {
        this.ISO = ISO;
        this.nome = nome;
        this.dimensao = dimensao;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getISO() {
        return ISO;
    }

    public void setISO(String ISO) {
        this.ISO = ISO;
    }

    public int getPopulacao() {
        return populacao;
    }

    public void setPopulacao(int populacao) {
        this.populacao = populacao;
    }

    public double getDimensao() {
        return dimensao;
    }

    public void setDimensao(double dimensao) {
        this.dimensao = dimensao;
    }

    public boolean equals(Pais outro) {
        if (outro == null) return false;
        return this.ISO.equals(outro.getISO());
    }

    public boolean limitrofe(Pais outro) {
        for (Pais vizinho : this.vizinhos) {
            if (vizinho != null && vizinho.equals(outro)) {
                return true;
            }
        }
        return false;
    }

    public double densidadePais() {
        return this.populacao / this.dimensao;
    }

    public ArrayList<Pais> getVizinhosComuns(Pais outro) {
        ArrayList<Pais> comuns = new ArrayList<>();

        for (Pais p : this.vizinhos) {
            if (outro.limitrofe(p)) {
                comuns.add(p);
            }
        }

        return comuns;
    }
}
