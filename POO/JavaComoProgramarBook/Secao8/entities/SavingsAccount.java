/*
Crie uma classe SavingsAccount. Utilize uma variável static annualInterestRate para armaze
nar a taxa de juros anual para todos os correntistas. Cada objeto da classe contém uma variável de instância private savingsBalance 
para indicar a quantidade que o poupador atualmente tem em depósito. Forneça o método calculateMonthlyInterest para calcular 
os juros mensais multiplicando o savingsBalance por annualInterestRate dividido por 12 — esses juros devem ser adicionados 
ao savingsBalance. Forneça um método static modifyInterestRate que configure o annualInterestRate com um novo 
valor. Escreva um programa para testar a classe SavingsAccount. Instancie dois objetos savingsAccount, saver1 e saver2, com 
saldos de R$ 2.000,00 e R$ 3.000,00, respectivamente. Configure annualInterestRate como 4% e então calcule o juro mensal de cada 
um dos 12 meses e imprima os novos saldos para os dois poupadores. Em seguida, configure annualInterestRate para 5%, calcule a 
taxa do próximo mês e imprima os novos saldos para os dois poupadores.
*/

package POO.JavaComoProgramarBook.Secao8.entities;

public class SavingsAccount {
    static int annuaInterestRate;
    private double savingsBalance;
    
    public SavingsAccount(int annuaInterestRate, double savingsBalance) {
        SavingsAccount.annuaInterestRate = annuaInterestRate;
        this.savingsBalance = savingsBalance;
    }

    public void calculateMonthlyInterest() {
        this.savingsBalance += (getSavingsBalance() * getAnnuaInterestRate()) / 12;
    }

    public static void modifyInterestRate(int newAnnualInterestRate) {
        SavingsAccount.annuaInterestRate = newAnnualInterestRate;
    }

    public static int getAnnuaInterestRate() {
        return annuaInterestRate;
    }

    public static void setAnnuaInterestRate(int annuaInterestRate) {
        SavingsAccount.annuaInterestRate = annuaInterestRate;
    }

    public double getSavingsBalance() {
        return savingsBalance;
    }

    public void setSavingsBalance(double savingsBalance) {
        this.savingsBalance = savingsBalance;
    }

    

}
