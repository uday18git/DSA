// insert an element from unsorted array to its correct position in sorted array
// sortd, unsorted
// 12     45 23 51 19 8
// take 45 and place it in its correct position
// sorted,   unsorted
// 12 45    23 51 19 8
// 12 23 45 51 19 8


#include <bits/stdc++.h> 
using namespace std;
// int main(){
//     // const int n=10;
//     // int arr[n];
//     vector<int> arr = {10,9,8,7};
//     int n=arr.size();
//     for(int i=1;i<n;i++)
//     {
//         int current = arr[i]; // first element of current unsorted array 
//         int j=i-1; // we will go from one element before the first element of the current unsorted array to 0 and until bigger number is there move the bigger number front
//         while(j>=0 && arr[j]>current) //  we can start from 0 and go till i-1 , but its more hectic, this approach is easier
//         {
//             arr[j+1]=arr[j]; //  moving bigger elements forward
//             j--;
//         }
//         arr[j+1]=current; // and putting the current in its correct place
//     }
//     for(auto i:arr)
//     {
//         cout<<i<<" ";
//     }
// return 0;
// }


// // recursive insertion sort;

// void insert(vector<int>&arr,int temp)
// {
//     if(arr.size()==0 || arr.back()<temp)
//     {
//         arr.push_back(temp);
//         return;
//     }
//     // remove one element and again try to insert 
//     int val = arr.back();
//     arr.pop_back();
//     insert(arr,temp); 
//     arr.push_back(val);
// }
// void sort(vector<int> &arr)
// {
//     if(arr.size()==1)
//     {
//         return ;
//     }
//     int temp = arr.back();
//     arr.pop_back();
//     sort(arr);
//     insert(arr,temp);
// }

// insertion sort is a sorting algorithm , where we maintain the array in two portions , 
// sorted and unsorted ....
// initially the first element is in the sorted part,
// we will start the iteration from the 1st element and we will take that as current and iterate back in the sorted part 
// and insert the current element in the sorted part
int main()
{
    vector<int> arr = {10,9,8,7};
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int curr = arr[i];
        while(j>=0 && arr[j]>curr)
        {
            arr[j+1] = arr[j]; // shifting the larger elements to the right
            j--;
        }
        arr[j+1 ] = curr;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}