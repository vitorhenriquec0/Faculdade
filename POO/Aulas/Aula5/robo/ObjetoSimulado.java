package POO.Aulas.Aula5.robo;

public class ObjetoSimulado {
    private int x, y, z;
    private int largura, altura;

    public ObjetoSimulado(int x, int y, int largura, int altura) {
        this.x = x;
        this.y = y;
        this.largura = largura;
        this.altura = altura;
    }

    public void desenha() {
        System.out.printf("Desenhando objeto simulado em: (%d, %d)...", x, y);
    }

    public int getX() {
        return x;
    }
    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }
    public void setY(int y) {
        this.y = y;
    }
}
