package POO.ListaP1;

import java.util.ArrayList;
import POO.ListaP1.Pais;

public class Continente {
    private String nome;
    private ArrayList<Pais> paises = new ArrayList<>();

    public Continente(String nome) {
        this.nome = nome;
    }

    public void addCountry(Pais novo) {
        paises.add(novo);
    }

    public double dimensaoTotal() {

        double soma = 0.0;

        if (!this.paises.isEmpty()) {

            for (Pais p : this.paises) {
                soma += p.getDimensao();
            }
        }
        return soma;
    }

    public int populacaoTotal() {

        int soma = 0;

        if (!this.paises.isEmpty()) {
            for (Pais p : this.paises) {
                soma += p.getPopulacao();
            }
        }
        return soma;
    }

    public double densidadeContinental() {
        return populacaoTotal() / dimensaoTotal();
    }

    public Pais maiorPopulacao() {
        Pais maior = paises.get(0);
        if (!this.paises.isEmpty()) {
            for (Pais p : paises) {
                if (p.getPopulacao() > maior.getPopulacao()) {
                    maior = p;
                }
            }
        }

        return maior;
    }

    public Pais menorPopulacao() {
        Pais menor = paises.get(0);

        if (!this.paises.isEmpty()) {
            for (Pais p : paises) {
                if (p.getPopulacao() < menor.getPopulacao()) {
                    menor = p;
                }
            }
        }
        return menor;
    }

    public Pais maiorDimensao() {
        Pais maior = paises.get(0);
        if (!this.paises.isEmpty()) {
            for (Pais p : paises) {
                if (p.getDimensao() > maior.getDimensao()) {
                    maior = p;
                }
            }
        }
        return maior;
    }

    public Pais menorDimensao() {
        Pais menor = paises.get(0);
        if (!this.paises.isEmpty()) 
            for (Pais p : paises) {
                if (p.getDimensao() < menor.getDimensao()) {
                    menor = p;
                }
        }

        return menor;
    }

}
