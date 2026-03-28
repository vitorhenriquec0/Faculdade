package Exercício1;
import java.util.*;

import Exercício1.entities.Conta;

public class Exercício {
    public static void main(String[] args) {

        Conta conta1 = new Conta("Heitor", 8878503, 10.54, 8080, 014305);
        Conta conta2 = new Conta("Vitor", 3983443, 1054.84, 9090, 014305);
        Conta conta3 = new Conta("Vitoria", 9358302, 1.54, 7070, 014305);

        System.out.println(conta1);
        System.out.println(conta2);
        System.out.println(conta3);

        conta1.deposito(1000000.00);
        conta2.deposito(10000000.00);
        conta3.deposito(0.83);
        conta3.deposito(100000000.00);

        System.out.println();

        System.out.println(conta1);
        System.out.println(conta2);
        System.out.println(conta3);
    }
}
