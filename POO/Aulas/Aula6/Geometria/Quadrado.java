package POO.Aulas.Aula6.Geometria;

public class Quadrado implements ObjetoGeometrico {
    private Ponto2D origem;
    private int lado;

    public Quadrado(Ponto2D origem, int lado) {
        this.origem = origem;
        this.lado = lado;
    }

    public Ponto2D getCentro() {
        return new Ponto2D(origem.getX() + lado / 2, origem.getY() + lado / 2);
    }

    public double getArea() {
        return lado * lado;
    }

    public double getPerimetro() {
        return 4 * lado;
    }

}
