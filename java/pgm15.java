interface Calc
{
    public int res(int x,int y);
}
public class pgm15 
{
    public static void main(String[] args) {
        Calc a = (x,y)->(x+y);
        System.out.println("sum is"+a.res(2,3));
        Calc b = (x,y)->(x*y);
        System.out.println("product is"+b.res(2,10));
    }
}