package entities;

public class Invoice {
    private String number;
    private String description;
    private int quantity;
    private Double price;

    public Invoice(String number, String description, int quantity, Double price) {
        this.number = number;
        this.description = description;
        this.quantity = quantity;
        this.price = price;
    }

    public Double getInvoiceAccount() {
        if (getPrice() < 0.0) {
            setPrice(0.0);
        }
        if (getQuantity() < 0) {
            setQuantity(0);
        }
        return getPrice() * getQuantity();
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }


}
