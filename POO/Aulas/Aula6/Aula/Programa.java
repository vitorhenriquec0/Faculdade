package POO.Aulas.Aula6.Aula;

import POO.Aulas.Aula6.Aula.Pessoa;

import java.io.*;
import java.util.*;

public class Programa {
     static ArrayList <String> nomes = new ArrayList <String>();
    public static void main(String[] args) {
        Pessoa p = new Pessoa("Jorge", 25, 'M');
        salvar(p);
        p = new Pessoa("Maria", 12, 'F');
        salvar(p);
        ler();
        System.out.println(nomes.get(0) + " " + nomes.get(1));
    }
}

public static void salvar(Pessoa p) {
    Scanner e = new Scanner(System.in);
    System.out.println("Digite o nome do arquivo: ");
    String nomeArquivo = e.nextLine();
    String path = "/home/vitor-henrique-cardoso/Faculdade/POO/Aulas/Aula6/Aula/" + nomeArquivo + ".txt";

    try {
        File arq = new File(path);
        FileWriter w = new FileWriter(arq, true);
        w.write(p.getNome() + "\r\n");
        w.write(p.getIdade() + "\r\n");
        w.write(p.getSexo() + "\r\n");
        w.close();
    } catch (IOException ex) {
        System.out.println("Erro");
    }
}

public static void ler() {
    Scanner e = new Scanner(System.in);
    System.out.println("Digite o nome do arquivo: ");
    String nomeArquivo = e.nextLine();
    String path = "/home/vitor-henrique-cardoso/Faculdade/POO/Aulas/Aula6/Aula/" + nomeArquivo + ".txt";

    try {
        File arq = new File(path);
        FileReader r = new FileReader(arq);
        BufferedReader leitor = new BufferedReader(r);
        String linha = "texto";
        int cont = 0;

        while (linha!=null) {
            linha = leitor.readLine();
            if(cont%3 == 0 && linha!=null) {
                nomes.add(linha);
                cont++;
            }
        }
        r.close();
    } catch(IOException ex) {
        System.out.println("ERRO");
    }
}