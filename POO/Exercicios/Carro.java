package POO.Exercicios;

public class Carro extends Veiculo implements Transporte {

    public Carro(String modelo) {
        this.modelo = modelo;
    }

    public void abastecer() {
        System.out.println("Abastecendo...");
    }
    public void mover() {
        System.out.println("Acelerando o carro modelo: " + modelo);
    }
}
