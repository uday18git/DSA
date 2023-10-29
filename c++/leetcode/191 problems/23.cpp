// optimized,  no idea how it works , magical
#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    map<int,int> m;
    m[0]=1;
    int n=a.size();
    int xr=0,x,count=0;
    for(int i=0;i<n;i++)
    {
        xr = xr^a[i];
        x=xr^b;
        count+=m[x];
        m[xr]++;
    }
    
    return count;
}

// brute
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n=a.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        int currxor=0;
        for(int j=i;j<n;j++)
        {
            currxor = currxor^a[j];
            if(currxor==b)
            {
                count++;
            }
        }
    }
    return count;
}