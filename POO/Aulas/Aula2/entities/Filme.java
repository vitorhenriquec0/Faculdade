package entities;

public class Filme {
    private String name;
    private int[] ranking = new int[10];
    private Double media;

    public Filme(String name, int[] ranking, Double media) {
        this.name = name;
        this.ranking = ranking;
        this.media = media;
    }

    public Filme(String name, int[] ranking) {
        this.name = name;
        this.ranking = ranking;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int[] getRanking() {
        return ranking;
    }

    public void setRanking(int[] ranking) {
        this.ranking = ranking;
    }

    public Double getMedia() {
        return media;
    }

    public void calculateMedia(int criticos) {
        Double media = 0.0;
        for (int i = 0; i < 10; i++) {
            media += (this.ranking[i] * i);
        }
        media /= criticos;
        this.media = media;
    }

    @Override
    public String toString() {
        return "\nFilme: " + name + "\nMedia: " + media;
    }
}
