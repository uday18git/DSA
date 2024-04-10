struct meeting{
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting s1,meeting s2)
{
    if(s1.end>s2.end)return false;
    else if(s1.end<s2.end)return true;
    else if(s1.pos>s2.pos)return false;
    return true;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n=start.size();
    struct meeting meetings[n];
    for(int i=0;i<n;i++)
    {
        meetings[i].start = start[i]; 
        meetings[i].end = end[i];
        meetings[i].pos = i+1;
    }
    sort(meetings,meetings+n,comparator);

    int limit = meetings[0].end;
    // vector<int> ans;
    // ans.push_back(meetings[0].pos);
    int count=1;
    for(int i=1;i<n;i++)
    {
        if(meetings[i].start>limit)
        {
            // ans.push_back(meetings[i].pos);
            count++;
            limit = meetings[i].end;
        }
    }
    return count;


}