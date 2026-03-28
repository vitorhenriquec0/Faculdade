package Exercício2.entities;

import java.util.ArrayList;
import Exercício2.entities.Conta;

public class Agencia {
    private String nome;
    private int agencia;
    private int banco;
    private ArrayList<Conta> contas;

    public Agencia(String nome, int agencia, int banco) {
        this.nome = nome;
        this.agencia = agencia;
        this.banco = banco;
        this.contas = new ArrayList<Conta>();
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setAgencia(int agencia) {
        this.agencia = agencia;
    }

    public int getAgencia() {
        return agencia;
    }

    public void setBanco(int banco) {
        this.banco = banco;
    }

    public int getBanco() {
        return banco;
    }

    public Conta buscarConta(long conta) {
        for (Conta c : contas) {
            if (c.getConta() == conta) {
                return c;
            }
        }
        System.out.println("Conta não encontrada.");
        return null;
    }
}
