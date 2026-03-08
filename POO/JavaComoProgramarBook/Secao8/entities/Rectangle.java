/*
(Classe Rectangle) Crie uma classe Rectangle com os atributos length e width, cada um dos quais assume o padrão de 1. Forneça 
os métodos que calculam o perímetro e a área do retângulo. A classe tem métodos set e get para o comprimento (length) e a largura 
(width). Os métodos set devem verificar se length e width são, cada um, números de ponto flutuante maiores que 0,0 e menores que 
20,0. Escreva um programa para testar a classe Rectangle.
*/

package POO.JavaComoProgramarBook.Secao8.entities;

public class Rectangle {
    private double length = 1.0;
    private double width = 1.0;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public Rectangle() {
        this.length = 1.0;
        this.width = 1.0;
    }

    public double perimeter() {
        return 2 * getLength() + 2 * getWidth();
    }

    public double area() {
        return getLength() * getWidth();
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        if (length > 0.0 && length < 20.0) {
            this.length = length;
        }
        
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        if (width > 0.0 && width < 20.0) {
            this.width = width;
        }
        
    }

    
}
