#include <iostream>
#include<vector>
using namespace std;
int main() {
    // find the minimum difference element in a sorted array
    //. key will be given  we have to find  the element which has minimum difference from it
    // when we perform binary search and the key is  not there in the array
    // then the start and end will always point to the neighbours of key
    // if the key would have been present
    // basically we are finding out the floor and ceil of the element
    // nice
    vector<int> arr={1,3,8,10,15};
    int start=0;
    int end=arr.size()-1;
    int key=12;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            cout<<arr[mid]; // if the element is present then it will give the minimum difference with itself
        }
        else if(arr[mid]<key)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    cout<<arr[start]<<endl;
    cout<<arr[end]<<endl;

    return 0;
}

