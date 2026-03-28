import Exercício2.entities.Conta;
import Exercício2.entities.Agencia;

import java.util.Scanner;
import java.util.ArrayList;

public class BancoUNESP{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int escolha = 0, numConta, idConsulta, i;
        float valor;
        String nome, cpf;
        private ArrayList<Conta> contas;
        while(escolha!=6){
            System.out.println("Escolha o que fazer:");
            System.out.println("1 - Criar nova conta");
            System.out.println("2 - Consultar saldo");
            System.out.println("3 - Realizar depósito");
            System.out.println("4 - Realizar saque");
            System.out.println("5 - Listar dados de conta");
            System.out.println("6 - Encerrar programa");
            escolha = sc.nextInt();
            sc.nextLine();
            switch(escolha){
                case 1:
                    System.out.println("Insira o nome: ");
                    nome = sc.nextLine();
                    System.out.println("Insira o CPF: ");
                    cpf = sc.nextLine();
                    contas.add(new Conta(nome, cpf));
                    numConta = contas[Conta.totalContas-1].getNumConta();
                    System.out.println("Conta criada com ID: " +numConta);
                    break;
                case 2:
                    System.out.println("Insira o ID da conta: ");
                    idConsulta = sc.nextInt();
                    for(i = 0;i<Conta.totalContas;i++){
                        if(idConsulta == contas[i].getNumConta()){
                            System.out.printf("Saldo: R$ %.2f", contas[i].getSaldo());
                            break;
                        }
                    }
                    if(i==Conta.totalContas)
                        System.out.println("Conta inexistente");
                    break;
                case 3:
                    System.out.println("Insira o ID da conta: ");
                    idConsulta = sc.nextInt();
                    for(i = 0;i<Conta.totalContas;i++){
                        if(idConsulta == contas[i].getNumConta()){
                            System.out.println("Insira o valor a ser depositado: ");
                            valor = sc.nextFloat();
                            contas[i].depositar(valor);
                            break;
                        }
                    }
                    if(i==Conta.totalContas)
                        System.out.println("Conta inexistente");
                    break;
                case 4:
                    System.out.println("Insira o ID da conta: ");
                    idConsulta = sc.nextInt();
                    for(i = 0;i<Conta.totalContas;i++){
                        if(idConsulta == contas[i].getNumConta()){
                            System.out.println("Insira o valor a ser sacado: ");
                            valor = sc.nextFloat();
                            contas[i].sacar(valor);
                            break;
                        }
                    }
                    if(i==Conta.totalContas)
                        System.out.println("Conta inexistente");
                    break;
                case 5:
                    System.out.println("Insira o ID da conta: ");
                    idConsulta = sc.nextInt();
                    for(i = 0;i<Conta.totalContas;i++){
                        if(idConsulta == contas[i].getNumConta()){
                            System.out.println("Nome: " +contas[i].getNome());
                            System.out.println("CPF: " +contas[i].getCpf());
                            System.out.println("Saldo: " +contas[i].getSaldo());
                            System.out.println("Num. da conta: " +contas[i].getNumConta());
                            System.out.println("Agencia: " +contas[i].getAgencia());
                            break;
                        }
                    }
                    if(i==Conta.totalContas)
                        System.out.println("Conta inexistente");
                    break;
                    
                    
            }
        }
    }
}