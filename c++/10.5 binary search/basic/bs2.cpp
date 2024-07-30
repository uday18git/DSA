// first occurance of an element
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 3, 4, 5};
    int key = 3;
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end) // when this while loop will break start will be at the first occurance of the target, its magic
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << start << endl;
    return 0;
}
// last occurance of an element
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int> arr = {1, 2, 3, 4, 4, 5};
//     int key = 2;
//     int start = 0;
//     int end = arr.size() - 1;
//     while (start <= end) // when this while loop will break end will be at the last occurance of the target, its magic
//     {
//         int mid = start + (end - start) / 2;
//         if (arr[mid] <= key)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     cout << end << endl; // instead of returning this you can store it also

//     return 0;
// }

// // you can do this using lower_bound and upper_bound also

// // count of an element in sorted array
// // sorted is given so we can do in binary search
// // first occurance - last occurance  is coming to my mind
// // correct
// int count(vector<int>& arr, int n, int x) {
// 	// Write Your Code Here
// 	// total occurances of a number in array
// 	// last occurance - first occurance + 1
// 	int start=0;
// 	int end=n-1;
// 	// code for first occurance
// 	while(start<=end)
// 	{
// 		int mid = start+(end-start)/2;
// 		if(arr[mid]>=x)
// 		{
// 			end=mid-1;
// 		}
// 		else start=mid+1;
// 	}
// 	int focc = start;
// 	start=0;
// 	end=n-1;
// 	// code for last occurance
// 	while(start<=end)
// 	{
// 		int mid= start+(end-start)/2;
// 		if(arr[mid]<=x)
// 		{
// 			start=mid+1;
// 		}
// 		else
// 		{
// 			end=mid-1;
// 		}
// 	}
// 	int locc = end;
// 	int ans = locc-focc+1;
// }
