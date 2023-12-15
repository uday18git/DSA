// first occurance of an element
// #include <bits/stdc++.h> 
// using namespace std;
// int main(){
//     vector<int> arr = {1,2,3,3,3,4,4,5};
//     int key=2;
//     int start=0;
//     int end=arr.size()-1;
//     while(start<=end)
//     {
//         int mid=start+ (end-start)/2;
//         if(arr[mid]>=key)
//         {
//             end=mid-1;
//         }
//         else
//         {
//             start=mid+1;
//         }
//     }
//     cout<<start<<endl;

// return 0;
// }
//  last occurance of an element
#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int> arr = {1,2,3,3,3,4,4,5};
    int key=2;
    int start=0;
    int end=arr.size()-1;
    while(start<=end)
    {
        int mid=start+ (end-start)/2;
        if(arr[mid]<=key)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    cout<<end<<endl;// instead of returning this you can store it also

return 0;
}

// you can do this using lower_bound and upper_bound also