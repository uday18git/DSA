class A {
    synchronized void displayTable(int n)
    {
        try
        {
            for(int i=1;i<11;i++)
            {
                System.out.println(n*i);
                Thread.sleep(1000);
            }
        }
        catch(Exception e)
        {

        }
    }
}
class Mul extends Thread
{
    int n;A a;
    Mul(A a,int n)
    {
        this.a=a;
        this.n= n;
    }
    public void run()
    {
        a.displayTable(n);
    }
}
public class pgm14
{
    public static void main(String[] args) {
        A a= new A();
        Mul m = new Mul(a, 9);
        Mul m1 = new Mul(a, 8);
        m.start();
        m1.start();
    }
}