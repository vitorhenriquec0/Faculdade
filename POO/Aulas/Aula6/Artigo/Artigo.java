package POO.Aulas.Aula6.Artigo;

public abstract class Artigo {
    protected String nome;
    protected String autor;
    protected String título;
    protected int ano;

    public Artigo(String nome, String autor, String título, int ano) {
        this.nome = nome;
        this.autor = autor;
        this.título = título;
        this.ano = ano;
    }

    public abstract boolean remover();

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getAutor() {
        return autor;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public String getTítulo() {
        return título;
    }

    public void setTítulo(String título) {
        this.título = título;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }
}
