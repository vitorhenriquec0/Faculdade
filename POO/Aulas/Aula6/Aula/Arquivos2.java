package POO.Aulas.Aula6.Aula;

import java.io.*;


public class Arquivos2 {
    public static void main(String[] args) {
        try {
            File arq = new File("/home/vitor-henrique-cardoso/Faculdade/POO/Aulas/Aula6/Aula/teste.txt");
            FileReader arqRead = new FileReader(arq);
            BufferedReader l = new BufferedReader(arqRead);
            String linha = l.readLine();
            while (linha != null) {
                System.out.println(linha);
                linha = l.readLine();
            }
            l.close();
        } catch (Exception e) {
            System.out.println("Erro");
        }
    }
}
