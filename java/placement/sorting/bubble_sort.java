import java.util.Scanner;
public class bubble_sort {
    public static void main(String args[])
    {
        int arr[] = new int[10];
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<10;i++)
        {
            arr[i] = sc.nextInt();
        }
        int counter=1;
        int n=10;
        while(counter<n)
        {
            for(int i=0;i<n-counter;i++)
            {
                if(arr[i]>arr[i+1])
                {
                    int temp;
                    temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
            }
            counter++;
        }
        for(int i=0;i<n;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
    
}
