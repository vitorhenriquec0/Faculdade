
import entities.HeartRates;
import java.util.Scanner;


public class exercicio16 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite o nome: ");
        String nome = sc.nextLine();
        System.out.println("Digite o sobrenome");
        String sobrenome = sc.nextLine();
        System.out.println("Digite o dia de nascimento: ");
        int dia = sc.nextInt();
        System.out.println("Digite o mês de nascimento: ");
        int mes = sc.nextInt();
        System.out.println("Digite o ano de nascimento: ");
        int ano = sc.nextInt();

        HeartRates pessoa1 = new HeartRates(nome, sobrenome, dia, mes, ano);

        System.out.println("Idade: " + pessoa1.getAge());
        System.out.println("Freq. Máxima: " + pessoa1.calcFreqMax() + " bpm");
        pessoa1.faixaAlvo();

        sc.close();
    }
}
