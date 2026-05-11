package POO.Aulas.Aula4.entities2;

public class Pessoa {

    public enum DiasSemana {
        SEGUNDA("Segunda-Feira"),
        TERCA("Terça-Feira"),
        QUARTA("Quarta-Feira"),
        QUINTA("Quinta-Feira"),
        SEXTA("Sexta-Feira");

        private final String descricao;

        DiasSemana(String descricao) {
            this.descricao = descricao;
        }

        public String getDescricao() {
            return descricao;
        }
    }

    private String nome;
    private int idade;
    private char sexo;
    private int faltas;

    public Pessoa(String nome, int idade, char sexo, int faltas) {
        this.nome = nome;
        this.idade = idade;
        this.sexo = sexo;
        this.faltas = faltas;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public char getSexo() {
        return sexo;
    }

    public void setSexo(char sexo) {
        this.sexo = sexo;
    }

    public int getFaltas() {
        return faltas;
    }

    public void registrarFalta() {
        this.faltas++;
    }
}
