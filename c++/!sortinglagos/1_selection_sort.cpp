#include <bits/stdc++.h> 
using namespace std;
// // shifts the smallest element to the first each time
// int main(){
//     vector<int> arr={5,2,4,9,10,13,6};
//     int n=arr.size();
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]<arr[i])
//             {
//                 swap(arr[j],arr[i]);
//             }
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         /* code */cout<<arr[i]<<" ";
//     }
    
    
// return 0;
// }
// RECURSIVE SELECTION SORT

void selection(int arr[],int startIndex,int n)
{
    if(startIndex==n-1)return;
    for(int i=n-2;i>=startIndex;i--)
    {
        if(arr[i]>arr[i+1])
        {
            int temp =arr[i];
            arr[i] = arr[i+1];
            arr[i+1]=temp;
        }
    }
    selection(arr,startIndex+1,n);
}

int main()
{
    int arr[]={5,2,4,9,10,13,6};
    selection(arr,0,7);
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}