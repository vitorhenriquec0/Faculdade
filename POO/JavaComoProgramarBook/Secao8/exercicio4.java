/*
(Classe Rectangle) Crie uma classe Rectangle com os atributos length e width, cada um dos quais assume o padrão de 1. Forneça 
os métodos que calculam o perímetro e a área do retângulo. A classe tem métodos set e get para o comprimento (length) e a largura 
(width). Os métodos set devem verificar se length e width são, cada um, números de ponto flutuante maiores que 0,0 e menores que 
20,0. Escreva um programa para testar a classe Rectangle.
*/

package POO.JavaComoProgramarBook.Secao8;

import POO.JavaComoProgramarBook.Secao8.entities.Rectangle;
import java.util.Scanner;

public class exercicio4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Rectangle rectangle = new Rectangle();

        System.out.println("Digite o comprimento do retângulo: ");
        double length = sc.nextDouble();
        rectangle.setLength(length);
        System.out.println("Digite a largura do retângulo: ");
        double width = sc.nextDouble();
        rectangle.setWidth(width);

        System.out.println("Perimetro: " + rectangle.perimeter());
        System.out.println("Area: " + rectangle.area());


        sc.close();
    }
}
