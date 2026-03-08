/*
(Calculadora de frequência cardíaca alvo) Ao fazer exercícios físicos, você pode utilizar um monitor de frequência cardíaca para ver 
se sua frequência permanece dentro de um intervalo seguro sugerido pelos seus treinadores e médicos. Segundo a American Heart Associa
tion (AHA) (www.americanheart.org/presenter.jhtml?identifier=4736), a fórmula para calcular a frequência cardíaca 
máxima por minuto é 220 menos a idade em anos. Sua frequência cardíaca alvo é um intervalo entre 50-85% da sua frequência cardíaca 
máxima. [Observação: essas fórmulas são estimativas fornecidas pela AHA. As frequências cardíacas máximas e alvo podem variar com 
base na saúde, capacidade física e sexo da pessoa. Sempre consulte um médico ou profissional de saúde qualificado antes de começar 
ou modificar um programa de exercícios físicos.] Crie uma classe chamada HeartRates. Os atributos da classe devem incluir o nome, 
sobrenome e data de nascimento da pessoa (consistindo em atributos separados para mês, dia e ano de nascimento). Sua classe deve ter um 
construtor que receba esses dados como parâmetros. Para cada atributo forneça métodos set e get. A classe também deve incluir um método 
que calcule e retorne a idade (em anos), um que calcule e retorne a frequência cardíaca máxima e um que calcule e retorne a frequência 
cardíaca alvo da pessoa. Escreva um aplicativo Java que solicite as informações da pessoa, instancie um objeto da classe HeartRates e 
imprima as informações a partir desse objeto — incluindo nome, sobrenome e data de nascimento da pessoa — calcule e imprima a idade 
da pessoa (em anos), seu intervalo de frequência cardíaca máxima e sua frequência cardíaca alvo.
*/

package entities;

import java.time.LocalDate;

public class HeartRates {
    private String nome;
    private String sobrenome;
    private int day;
    private int month;
    private int year;

    public HeartRates(String nome, String sobrenome, int day, int month, int year) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public int getAge() {
        LocalDate hoje = LocalDate.now();
        int idade = hoje.getYear() - getYear();

        if (hoje.getMonthValue() < getMonth() ||
            (hoje.getMonthValue() == getMonth() && hoje.getDayOfMonth() < getDay())) {
            idade--;
        }

        return idade;
    }

    public int calcFreqMax() {
        return 220 - getAge();
    }

    public void faixaAlvo() {
        int freqMax = calcFreqMax();
        double faixaMin = freqMax * 0.50;
        double faixaMax = freqMax * 0.85;

    System.out.printf("%nFaixa alvo: %.1f bpm a %.1f bpm%n", faixaMin, faixaMax);
}

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public void setSobrenome(String sobrenome) {
        this.sobrenome = sobrenome;
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }


}
