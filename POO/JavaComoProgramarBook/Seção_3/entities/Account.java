package entities;

public class Account {
    private String name;
    private double balance;

    public Account(String name, double balance) {
        this.name = name;
        
        if (balance > 0.0) {
            this.balance = balance;
        }
    }

    public void deposit(double depositAmount) {
        if (depositAmount > 0.0) {
            balance += depositAmount;
        }
    }

    public void withdraw(double withdrawValue) {
        if (withdrawValue <= 0.0) {
            return;
        }

        if (getBalance() >= withdrawValue) {
            this.balance -= withdrawValue;
        } else {
            System.out.println("Withdrawal amount exceeded account balance");
        }
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getBalance() {
        return balance;
    }
}
