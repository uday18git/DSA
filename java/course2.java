import java.util.Scanner ;
public class course2 {
    public static void main(String[] args)
    {
        
        Scanner sc = new Scanner(System.in);
        int[] marks = new int[10];
        System.out.println(marks.length);
        int key;
        System.out.println("Enter the key");
        key = sc.nextInt();
        for(int i=0;i<marks.length;i++)
        {
            marks[i]=sc.nextInt();
        }
        int ans=0;
        for(int i: marks)//error here itll take the value for each !!!!
        {
            if(i==key)//error fixed
            {
                
                break;
            }
            ans++;   
        }
        System.out.println(ans);
    }
}
