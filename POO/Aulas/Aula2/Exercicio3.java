import java.util.*;

import Exercício1.entities.Filme;

public class Exercicio3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String name;
        int nota;

        List<entities.Filme> filmes = new ArrayList<>();

        System.out.print("Digite o número de críticos: ");
        int criticos = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < 10; i++) {
            int[] ranking = new int[10];

            System.out.print("Digite o nome do filme " + (i + 1) + ":");
            name = sc.nextLine();

            for (int j = 1; j <= criticos; j++) {
                System.out.print("Digite a nota do crítico " + j + ": ");
                nota = sc.nextInt();
                if (nota >= 1 && nota <= 10) {
                    ranking[nota - 1]++;
                } else {
                    System.out.println("Nota inválida. Digite entre 1 e 10.");
                }
            }

            sc.nextLine();

            Filme filme = new Filme(name, ranking);
            filme.calculateMedia(criticos);

            filmes.add(filme);
        }

        double maiorMedia = Double.MIN_VALUE;
        Filme vencedor = null;

        for (Filme filme : filmes) {
            double media = filme.getMedia();
            if (media > maiorMedia) {
                maiorMedia = media;
                vencedor = filme;
            }
        }

        System.out.print("O vencedor do Oscar é: " + vencedor);

        sc.close();
    }
}
