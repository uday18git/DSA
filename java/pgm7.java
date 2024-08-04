class Customer 
{
    private int ID;
    private String Name;
    private int discount;
    Customer(int ID,String Name,int discount)
    {
        this.Name = Name;
        this.ID=ID;
        this.discount=discount;
    }
    int getID()
    {
        return ID;
    }
    String getName()
    {
        return Name;
    }
    int getDiscount()
    {
        return discount;
    }
    void setDiscount(int discount)
    {
        this.discount=discount;
    }
    public String toString()
    {
        return Name + "("+ID +")";
    }
}
class Invoice
{
    private int ID;
    private Customer customer;
    private double amount ;
    Invoice(int ID,Customer customer,double amount)
    {
        this.ID = ID;
        this.customer = customer;
        this.amount = amount;
    }
    int getID()
    {
        return ID;
    }
    Customer getCustomer()
    {
        return customer;
    }
    void setCustomer(Customer customer) {
        this.customer = customer;
    }
    String getAmount()
    {
        return Double.toString(amount);
    }
    void setAmount(double amount)
    {
        this.amount = amount;
    }
    String getCustomerName()
    {
        return customer.getName();
    }
    double getAmountAfterDiscount()
    {
        return (amount*customer.getDiscount())/100;
    }
}

public class pgm7 {
    
}
