// import java.util.Scanner;
import java.util.*;
public class pgm16 {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String s;
        System.out.println("Enter String");
        s = sc.nextLine();
        int c = 0;
        char ch = s.charAt(0);
        for(int i=1;i<s.length();i++)
        {
            if(s.charAt(i)==ch)
                c++;
            ch = s.charAt(i);
        }
        System.out.println(c);

    }
}
