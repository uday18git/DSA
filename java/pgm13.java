import java.util.Scanner;

class Triangle extends Exception
{
    public String toString()
    {
        return "Not a acceptable traingle"; 
    }
}
public class pgm13
{
    public static void main(String[] args) {
        int a,b,c;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        try
        {
            if(a+b>c && b+c>a && c+a>b)
            {
                System.out.println("Valid Triangle");
            }
            else
            {
                throw new Triangle();
            }
        }
        catch(Triangle e)
        {
            System.out.println(e);
        }
    }
}