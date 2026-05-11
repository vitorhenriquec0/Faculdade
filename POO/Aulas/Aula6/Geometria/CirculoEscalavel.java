package POO.Aulas.Aula6.Geometria;

public class CirculoEscalavel implements ObjetoGeometrico, Escalavel {
    private Ponto2D centro;
    private int raio;

    public CirculoEscalavel(Ponto2D centro, int raio) {
        this.centro = centro;
        this.raio = raio;
    }

    public Ponto2D getCentro() {
        return centro;
    }

    public double getArea() {
        return Math.PI * raio * raio;
    }

    public double getPerimetro() {
        return 2 * Math.PI * raio;
    }

    public void amplia(double escala) {
        raio *= escala;
    }

    public void reduz(double escala) {
        raio /= escala;
    }

    public void espelha() {
        centro = new Ponto2D(-centro.getX(), centro.getY());
    }
}
