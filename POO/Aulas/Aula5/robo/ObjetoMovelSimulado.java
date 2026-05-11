package POO.Aulas.Aula5.robo;

import POO.Aulas.Aula5.robo.ObjetoSimulado;
import POO.Aulas.Aula5.robo.Direcoes;

public class ObjetoMovelSimulado extends ObjetoSimulado {
    public ObjetoMovelSimulado(int x, int y, int l, int a) {
        super(x, y, l, a);
    }

    public void movimenta(Direcoes direcao) {
        int novoX, novoY;
        switch (direcao) {
            case NORTE: novoY = getY(); novoY--; setY(novoY); break;
            case SUL: novoY = getY(); novoY++; setY(novoY); break;
            case LESTE: novoX = getX(); novoX++; setX(novoX); break;
            case OESTE: novoX = getX(); novoX--; setX(novoX); break;
        }
    }
}
