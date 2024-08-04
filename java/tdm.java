import java.util.Scanner;
public class tdm
{
    public static void main(String[] args) {
        int i,n,temp,sq=0,qt,count=0,wt[],bt[],tat[],rem_bt[];
        float awt=0,atat=0;
        wt=new int[10];
        bt=new int[10];
        tat=new int[10];
        rem_bt=new int[10];
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the number of stations(maximum 10): ");
        n=sc.nextInt();
        System.out.println("Enter processing times for all stations: ");
        for(i=0;i<n;i++)
        {
            bt[i]=sc.nextInt();
            rem_bt[i]=bt[i];
        }
        System.out.println("Enter the frame size: ");
        qt=sc.nextInt();
        while(true)
        {
            for(i=0,count=0;i<n;i++)
            {
                temp=qt;
                if(rem_bt[i]==0)
                {
                    count++;
                    continue;
                }
                if(rem_bt[i]>qt)
                {
                    rem_bt[i]=rem_bt[i]-qt;
                }
                else if(rem_bt[i]>=0)
                {
                    temp = rem_bt[i];
                    rem_bt[i]=0;
                }
                sq=sq+temp;
                tat[i]=sq;
            }
            if(n==count)
            {
                break;
            }
        }
        System.out.println("-------------------------------------------");
        System.out.println("Station\tProcessing Time\tCompletionTime\t WaitingTime");
        for(i=0;i<n;i++)
        {
            wt[i]=tat[i]-bt[i];
            awt=awt+wt[i];
            atat = atat+tat[i];
            System.out.println("\n"+(i+1)+"\t"+
            bt[i]+"\t\t"+tat[i]+"\t\t"+wt[i]);
        }
    }
}