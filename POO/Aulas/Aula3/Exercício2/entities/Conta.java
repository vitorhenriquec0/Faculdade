package Exercício2.entities;

public class Conta {
    private String nome;
    private String CPF;
    private Double saldo;
    private long conta;
    private int agencia;

    public Conta(String nome, String CPF) {
        this.nome = nome;
        this.CPF = CPF;
    }

    public Conta(String nome, String CPF, Double saldo, long conta, int agencia) {
        this.nome = nome;
        this.CPF = CPF;
        this.saldo = saldo;
        this.conta = conta;
        this.agencia = agencia;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setCPG(String CPF) {
        this.CPF = CPF;
    }

    public String getCPF() {
        return CPF;
    }

    public Double getSaldo() {
        return saldo;
    }

    public void setConta(long conta) {
        this.conta = conta;
    }

    public long getConta() {
        return conta;
    }

    public void setAgencia(int agencia) {
        this.agencia = agencia;
    }

    public int getAgencia() {
        return agencia;
    }

    public void deposito(Double valor) {
        this.saldo += valor;
    }

    public void saque(Double valor) {
        this.saldo -= valor;
    }

    @Override
    public String toString() {
        return "Conta [nome=" + nome + ", CPF=" + CPF + ", saldo=" + saldo + ", conta=" + conta + ", agencia=" + agencia + "]";
    }

    
}
