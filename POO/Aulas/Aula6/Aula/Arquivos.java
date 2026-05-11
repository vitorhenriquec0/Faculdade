package POO.Aulas.Aula6.Aula;

import POO.Aulas.Aula6.Aula.Pessoa;

import java.io.*;

public class Arquivos {
    public static void main(String[] args) {
        Pessoa p = new Pessoa("Jorge", 24, 'M');
        try {
            File arq = new File("/home/vitor-henrique-cardoso/Faculdade/POO/Aulas/Aula6/Aula/teste.txt");
            FileWriter objEscritor = new FileWriter(arq, true);
            objEscritor.write(p.getNome() + "\r\n");
            objEscritor.write("Teste");
            objEscritor.close();
        } catch (IOException e) {
            System.out.println("Erro");
        }
    }
}
