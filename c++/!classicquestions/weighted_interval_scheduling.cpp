#include<iostream>
using namespace std;
#define MAX 20
int M[MAX];
// first we sort based on the finish time of the intervals
// then we find the p(j) which is the last interval which is compatible with j
// then recurrence relation is M(j)=max(vj+M(p(j)),M(j-1))
//  which covers two case , we take the jth interval(so if we take we have to take it with its last compatible interval(pj)) or we dont take the jth interval
struct Interval
{
    int startTime;
    int finishTime;
    int weight;
};

class WIS
{
    Interval I[MAX];
    public:
        int n;
        WIS()
        {
            for(int i=0;i<=MAX;i++)
            {
                M[i]=0;
            }
        }
        void sortIntervals();
        int mComputeOpt(int );
        void input();
        int p(int);
};

int WIS::p(int j)
{
    for(int i=j-1;i>0;i--)
    {
        if(I[i].finishTime<=I[j].startTime)
        {
            return i;
        }
        return 0;
    }
}

void WIS::input()
{
    cout<<"Enter no of intervals:";
    cin>>n;
    cout<<"Enter the starting time <Si>. Finishing time<fi> and weight Value <vi> for the intervals:";
    cout<<"\n\nSi Fi Vi\n";
    for(int i=1;i<=n;i++)
    {
        cin>>I[i].startTime>>I[i].finishTime>>I[i].weight;
    }
}

void WIS::sortIntervals()
{
    Interval temp;
    int i,flag=1;
    for(i=1;i<=n && flag;i++)
    {
        flag=0;
        for(int j=1;j<=n-i;j++)
        {
            if(I[j].finishTime>I[j+1].finishTime)
            {
                temp=I[j];
                I[j]=I[j+1];
                I[j+1]=temp;
                flag=1;
            }
        }
    }
    cout<<"\nSorted Intervals are:\n";
    cout<<"\nSi Fi Vi\n";
    for(i=1;i<=n;i++)
    {
        cout<<I[i].startTime<<" "<<I[i].finishTime<<" "<<I[i].weight<<endl;
    }

}
int WIS::mComputeOpt(int j)
{
    if(j==0)
    {
        return 0;
    }
    else if(M[j])
    {
        return M[j];
    }
    else
    {
        M[j]=max(I[j].weight+mComputeOpt(p(j)),mComputeOpt(j-1));
    }
    return M[j];
}
