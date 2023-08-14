#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool sorted(int arr[],int n)
{
    if(n==1)
    {
        return true;
    }
    bool restarray = sorted(arr+1,n-1);
    return(arr[0]<arr[1] && restarray ); 
}
void insert(vector<int>&arr,int temp)
{
    if(arr.size()==0 || arr[arr.size()-1]<=temp)
    {
        arr.push_back(temp);
        return;
    }
    int t = arr[arr.size()-1];
    arr.pop_back();
    insert(arr,temp);
    arr.push_back(t);
}

void insertion_sort(vector<int> &arr)
{
    if(arr.size()==1) // at this(1) point the arr is sorted , so no further sorting needed 
    {
        return ;
    }
    int temp=arr[arr.size()-1];
    arr.pop_back();
    insertion_sort(arr);
    insert(arr,temp);
}
// we are making input small 
// first we pop_back and keep recursively calling insertion sort on it, now it will stop on 
// array size 1 , so now it will return and insert will be called , which will step by step sort each element of the array
int main(){
    vector<int> arr = {100,99,98,97,96};
    insertion_sort(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i];
    }

return 0;
}
// 1. Initial call: `insertion_sort({100, 99, 98, 97, 96})`
//     Since the size of the array is greater than 1, we proceed with the recursive calls.
// 2. Recursive call 1: `insertion_sort({100, 99, 98, 97})`
//     The last element, `96`, is stored in the `temp` variable, and the element is removed from the array. We now have `{100, 99, 98, 97}`.
// 3. Recursive call 2: `insertion_sort({100, 99, 98})`
//     The last element, `97`, is stored in the `temp` variable, and the element is removed from the array. We now have `{100, 99, 98}`.
// 4. Recursive call 3: `insertion_sort({100, 99})`
//     The last element, `98`, is stored in the `temp` variable, and the element is removed from the array. We now have `{100, 99}`.
// 5. Recursive call 4: `insertion_sort({100})`
//     Since the size of the array is 1, we reach the base case and return without making any changes. The array remains as `{100}`.
// 6. Now, we start unwinding the recursion.
//     The `insert` function is called with the `arr` vector being `{100}` and the `temp` value being `99`. The `arr` vector is modified to `{99, 100}`.
//     We continue unwinding the recursion and return to the previous level.
//     The `insert` function is called with the `arr` vector being `{99, 100}` and the `temp` value being `98`. The `arr` vector is modified to `{98, 99, 100}`.
//     Again, we continue unwinding the recursion and return to the previous level
//     The `insert` function is called with the `arr` vector being `{98, 99, 100}` and the `temp` value being `97`. The `arr` vector is modified to `{97, 98, 99, 100}`.
// 7. Finally, we return to the initial caller of `insertion_sort`.
//     The `insert` function is called with the `arr` vector being`{97, 98, 99, 100}` and the `temp` value being `96`. The `arr` vector is modified to `{96, 97, 98, 99, 100}`.
// 8. The initial caller of insertion_sort receives the modified array `{96, 97, 98, 99, 100}` and returns.
// The final sorted array is {96, 97, 98, 99, 100}.