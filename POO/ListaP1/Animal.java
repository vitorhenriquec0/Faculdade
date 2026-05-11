package POO.ListaP1;

public abstract class Animal {
    private String nome;

    public Animal(String nome) {
        this.nome = nome;
    }

    public abstract void emitirSom();

    public void dormir() {
        System.out.println("O animal está dormindo");
    }
}
