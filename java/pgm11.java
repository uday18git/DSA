class A extends Thread{
    public void run()
    {
        int i=0,c=0;
        while(c<3)
        {
            if(i%2==1)
            {
                System.out.println(i);
                c++;
            }
            i++;
        }
    }
}
class B extends Thread{
    int n;
    B(int n)
    {
        this.n=n;
    }
    public void run()
    {
        int rev=0,rem;
        while(n>0)
        {
            rem = n%10;
            rev = 10*rev+rem;
            n/=10;
        }
        System.out.println("Reversed Number = " + rev);
    }
}
public class pgm11
{
    public static void main(String[] args) {
        A a = new A();
        a.start();
        B b = new B(9124);
        b.start();
        try{
            a.join();
            b.join();
        }
        catch(Exception e){

        }
    }
}