class SavingsAccount 
{
    static int annualInterestRate;
    private double savingsBalance;
    SavingsAccount(int savingsBalance)
    {
        this.savingsBalance=savingsBalance;
    }
    void calculateMonthlyInterest()
    {
        double d =  savingsBalance*annualInterestRate/12;
        savingsBalance+=d;
    }
    static void modifyInterestRate(int x)
    {
        annualInterestRate=x; //*******//
    }
    void display()
    {
        System.out.println(savingsBalance);
    }
}

public class pgm6 {
    public static void main(String[] args) {
        SavingsAccount saver1 = new SavingsAccount(2000); 
        SavingsAccount saver2 = new SavingsAccount(3000); 
        SavingsAccount.modifyInterestRate(4);//very very important
        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();
        saver1.display();
        saver2.display();
        SavingsAccount.modifyInterestRate(5);//very very important
        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();
        saver1.display();
        saver2.display();


    }
}
