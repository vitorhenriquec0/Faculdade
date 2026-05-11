package POO.Aulas.Aula4;

import POO.Aulas.Aula4.entities.*;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        
        ArrayList<Time> times = new ArrayList<>();

        Time time1 = new Time("Comp", "CACIC", 0, 0, 0, 1);
        Time time2 = new Time("Bio", "CAEA", 0, 0, 0, 1);
        Time time3 = new Time("Letras", "CAL", 0, 0, 0, 2);
        Time time4 = new Time("Quimica", "CAQUA", 0, 0, 0, 2);
        Time time5 = new Time("Tradução", "CATRA", 0, 0, 0, 3);
        Time time6 = new Time("Engenharia", "CAEA", 0, 0, 0, 3);

        Jogo jogo1 = new Jogo().CriarJogo(time1, time2);
        jogo1.resultadoJogo(30, 1);

        Jogo jogo2 = new Jogo().CriarJogo(time3, time4);
        jogo2.resultadoJogo(3, 27);

        Jogo jogo3 = new Jogo().CriarJogo(time1, time2);
        jogo3.resultadoJogo(543, 2);
    }
}
