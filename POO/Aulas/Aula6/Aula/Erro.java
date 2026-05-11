package POO.Aulas.Aula6.Aula;

import java.util.ArrayList;

public class Erro {
    public static void main(String[] args) {
        ArrayList <String> lista = new ArrayList<String>();
        lista.add("Teste");
        lista.add("Aula");
        try {
            String novo = lista.get(1);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Erro: " + e.getMessage());
        }
        System.out.println("Continua...");
    }
}
