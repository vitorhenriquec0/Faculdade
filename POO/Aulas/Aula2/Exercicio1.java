package POO.Aulas.Aula2;

import POO.Aulas.Aula2.entities.Aluno;
import java.util.*;

public class Exercicio1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String nome;
        Double nota1;
        Double nota2;
        Double nota3;

        List<Aluno> alunos = new ArrayList<>();


        for (int i = 0; i < 3; i++) {
            System.out.println("Aluno " + (i + 1) + ":\n");
            System.out.print("Nome: ");
            nome = sc.nextLine();
            System.out.print("Nota 1: ");
            nota1 = sc.nextDouble();
            System.out.print("Nota 2: ");
            nota2 = sc.nextDouble();
            System.out.print("Nota 3: ");
            nota3 = sc.nextDouble();

            alunos.add(new Aluno(nome, nota1, nota2, nota3));
            sc.nextLine();
        }

        alunos.forEach(aluno -> {
            aluno.calcularMedia();
            System.out.printf("Aluno: %s | Media: %.2f%n", aluno.getNome(), aluno.getMedia());
        });

        sc.close();
    }
}
