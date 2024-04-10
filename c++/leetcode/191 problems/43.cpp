// n meetings in one room
#include<bits/stdc++.h>
using namespace std;
struct meeting
{
    int start;
    int end;
    int pos;
};
bool comparator(struct meeting m1,meeting m2)
{
    if(m1.end<m2.end)return true;
    else if(m1.end>m2.end)return false;
    else if(m1.end<m2.pos)return true; // this is to handle the case when they are equal, then it has to sort according to the position
    return false;
}

void maxMeetings(int s[],int e[],int n)
{
    struct meeting meet[n];
    for(int i=0;i<n;i++)
    {
        meet[i].start = s[i],meet[i].end=e[i],meet[i].pos=i+1;
    }
    sort(meet,meet+n,comparator);// sorting based on finish time
    vector<int> answer;
    int limit=meet[0].end;
    answer.push_back(meet[0].pos);
    for(int i=1;i<n;i++)
    {
        if(meet[i].start>limit)
        {
            limit=meet[i].end;
            answer.push_back(meet[i].pos);
        }
    }
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<" ";
    }

}
int main()
{
    return 0;
}

// APPROACH is sort based on finish times and (finish times because others wont work)
// take first meet's end as limit
// then keep updating limit and if meet's start value is greater than limit then we can add that