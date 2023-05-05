//minimum subarray size such that their sum>x
//approach 1 dabba approach
// approach sliding window
// define ans,sum & start(where the ans is starting)
// iterate over array & start adding elements to sum
// if sum>x ,remove elements from the start
// O(N)
// WORKS ONLY FOR POSITIVE NUMBERS
#include <bits/stdc++.h> 
using namespace std;
int smallestSubarrayWithSum(int arr[],int n,int x)
{
    int minLength=n+1;
    int start=0,end=0,sum=0;
    while(end<n)
    {
        while(sum<=x && end<n)
        {
            sum+=arr[end++];
        }
        while(sum> x && start<n)
        {
            minLength = min(minLength,end-start);
            sum-=arr[start++];
        }
    }
    return minLength;
}
int main(){
    int arr[] = {1,4,45,6,10,19};
    int x = 51;
    int n = 6;
    int minLength = smallestSubarrayWithSum(arr,n,x);
    minLength==n+1?cout<<"no such subarray exists":cout<<"Min length is : "<<minLength<<endl;
return 0;
}