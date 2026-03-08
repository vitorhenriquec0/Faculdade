/*
Modifique a classe Account (Figura 3.8) para fornecer um método chamado withdraw que retira dinheiro de uma Account.
Assegure que o valor de débito não exceda o saldo de Account. Se exceder, o saldo deve ser deixado inalterado
e o método deve imprimir uma mensagem que indica "Withdrawal amount exceeded account balance" [Valor de débito
excedeu o saldo da conta]. Modifique a classe AccountTest (Figura 3.9) para testar o método withdraw.
*/

import entities.Account;

public class exercicio11 {
    public static void main(String[] args) {

        Account myAccount = new Account("Vitor", 700.0);

        myAccount.withdraw(200.0);
        myAccount.withdraw(600.0);

        System.out.println("New balance: " + myAccount.getBalance());
    }
}