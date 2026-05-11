package POO.Aulas.Aula7;

import java.util.*;

public class ConjuntoDePalavras {
    private Set<String> lista;

    public ConjuntoDePalavras() {
        lista = new TreeSet<String>(); // ordenado
    }

    public void adiciona(String listaDePalavras) {
        String[] palavras = listaDePalavras.split(" ");
        for (String p : palavras) {
            lista.add(p.toLowerCase());
        }
    }

    public boolean existe(String palavra) {
        return lista.contains(palavra.toLowerCase());
    }

    public void imprime() {
        for (String p : lista) {
            System.out.println(p);
        }
    }

    public static void main(String[] args) {
        ConjuntoDePalavras cp = new ConjuntoDePalavras();
        cp.adiciona("O rato roeu a roupa do rei de Roma");
        cp.imprime();
        System.out.println(cp.existe("rato"));
        System.out.println(cp.existe("gato"));
    }
}
