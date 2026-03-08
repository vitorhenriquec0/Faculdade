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

package POO.JavaComoProgramarBook.Secao8;

import POO.JavaComoProgramarBook.Secao8.entities.SavingsAccount;

public class exercicio6 {
    public static void main(String[] args) {
        SavingsAccount saver1 = new SavingsAccount(2000.00);
        SavingsAccount saver2 = new SavingsAccount(3000.00);
        SavingsAccount.modifyInterestRate(4.0);
        for (int i = 0; i < 12; i++) {
            saver1.calculateMonthlyInterest();
            saver2.calculateMonthlyInterest();
        }
        System.out.println("Saldo de saver1: " + saver1.getSavingsBalance());
        System.out.println("Saldo de saver2: " + saver2.getSavingsBalance());
        SavingsAccount.modifyInterestRate(5.0);
        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();
        System.out.println("Saldo de saver1: " + saver1.getSavingsBalance());
        System.out.println("Saldo de saver2: " + saver2.getSavingsBalance());
    }
}
