// suppose arr={1,3,12,5,15,11}
//  k1=3 k2=6
//  k1th smallest 3rd element in sorted array
//  arr_sorted = {1,3,5,11,12,15}
//  3rd smallest is 5 and 6th smallest is 15 so sum between then is 11+12 so ans= 23
#include <bits/stdc++.h>
using namespace std;
int kth_smallest_element(vector<int> arr,int k)
{
    priority_queue<int> max_h;
    for(int i=0;i<arr.size();i++)
    {
        max_h.push(arr[i]);
        if(max_h.size()>k)max_h.pop();
    }
    return max_h.top();
}
int main()
{
    vector<int> arr={1,3,5,11,12,15};
    int k1=3,k2=6;
    int k1_th_smallest_element = kth_smallest_element(arr,k1);
    int k2_th_smallest_element = kth_smallest_element(arr,k2);
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>k1_th_smallest_element&& arr[i]<k2_th_smallest_element)
        {
            ans+=arr[i];
        }
    }
    cout<<ans;
    return 0;
}