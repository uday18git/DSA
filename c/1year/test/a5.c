#include<stdio.h>
void main()
// {
//     int i,t;
//     float count=0,avg=0,sum=0;
//     for(i=0;i<1000;i++)
//     {
//         scanf("%d",&t);
//         if(t==0)
//         continue;
//         else if(t<0)
//         break;
//         sum+=t;
//         count++;
//     }    
// avg=sum/count;
// printf("sum=%f,avg=%f",sum,avg);
// }

// for(i=0;i<1000;i++){
//         scanf("%d",&t);
//         if(t==0){
//             continue;
//         }
//         else if(t<0)
//         {
//             break;
//         }
//         sum+=t;
//         count++;
//     }
//     avg = sum/count;
//     printf("sum of number is %f , and average is %f",sum,avg);
{
    int i,t;
    float count=0,avg=0,sum=0;
    for(i=0;i<2000;i++)
    {
        scanf("%d",&t);
        if(t==0)
        {
            continue;
        }
        else if(t<0)
        {
            break;
        }
        else
        {
            sum+=t;
            count++;

        }
    }
    avg = sum/count;
    printf("sum = %f and avg = %f",sum,avg);
}