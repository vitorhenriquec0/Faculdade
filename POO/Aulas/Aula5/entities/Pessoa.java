package POO.Aulas.Aula5.entities;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Pessoa {
    private static final DateTimeFormatter FORMATO_DATA = DateTimeFormatter.ofPattern("dd/MM/yyyy");

    private String nome;
    private int identidade;
    private LocalDate nascimento;

    public Pessoa(String nome, int identidade, LocalDate nascimento) {
        this.nome = nome;
        this.identidade = identidade;
        this.nascimento = nascimento;
    }

    public String getNome() {
        return nome;
    }

    public int getIdentidade() {
        return identidade;
    }

    public LocalDate getNascimento() {
        return nascimento;
    }

    public String toString() {
        return "Nome: " + this.nome + "\nIdentidade: " + this.identidade + "\nNascimento: " + formatarData(this.nascimento);
    }

    protected String formatarData(LocalDate data) {
        return data.format(FORMATO_DATA);
    }
}
