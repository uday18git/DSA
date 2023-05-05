// problem -> you are given an array of denominations and a value X . you have to find the minimum number of coins required to make the change for the value X
// node -> we have infinite supply of coins
// example -> 1 2 5 10 20 50 100 200 500 2000
// X= 54
// strategy -> we will start from the largest denomination and keep on adding it to the answer until we can include it take it.
// 54-50->4
// else move on the next denomination
// only works for indian currency system
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    // sort(arr.begin(),arr.end(),greater<int>());//sorting in descending order
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(x>=arr[n-i-1])
        {
            ans+=x/arr[n-i-1]; //how many of those coins can we take
            x=x%arr[n-i-1];//remainder will be left
        }
    }
    // if(x)cout<<"X is there"<<x<<endl;
    // else{cout<<ans<<endl;}
    cout<<ans<<endl;
    // int i=n-1;
    // int count=0;
    // while(x)
    // {
    //     if(x>=arr[i])
    //     {
    //         x-=arr[i];
    //         count++;
    //     }
    //     else
    //     {
    //         i--;
    //     }
    // }

    // cout<<count<<endl;
    return 0;
}