import java.util.Scanner;
abstract class Vehicle 
{
    boolean hashelmet;
    int yom;
    abstract void getData();
    abstract void putData();
    Vehicle(boolean hashelmet,int yom)
    {
        this.hashelmet=hashelmet;
        this.yom=yom;
    }
    
}
class TwoWheeler extends Vehicle
{
    private String Brand;
    protected int cost;
    String EngineType;
    public String color;
    TwoWheeler(int n)
    {
        super(true,n);
    }
    void getData()
    {
        // normal input taking
    }
}
public class pgm2 {
    
    
}
