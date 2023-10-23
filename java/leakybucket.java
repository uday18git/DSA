import java.util.Scanner;
import java.lang.*;
public class leakybucket
{
    public static void main(String[] args) {
        int n,a[];
        a=new int[10];
        int buck_cap=4,rate=3,buck_rem=0,sent,recv;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of packets:");
        n=sc.nextInt();
        System.out.println("Enter the packets: ");
        for(int i=1;i<=n;i++)
        {
            a[i]=sc.nextInt();
        }
        System.out.println("\nClock\tPacket\tReceived\tSent\tRemaining\n");
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=0)
            {
                if(buck_rem+a[i]>buck_cap)
                {
                    recv=-1;
                }
                else
                {
                    recv = a[i];
                    buck_rem+=a[i];
                }
            }
            else
            recv=0;
            if(buck_rem!=0)
            {
                if(buck_rem>rate)
                {
                    sent=rate;
                    buck_cap-=rate;
                }
                else
                {
                    sent=buck_rem;
                    buck_rem=0
                }
            }
            else
            {
                sent=0;
            }
        }
    }
}