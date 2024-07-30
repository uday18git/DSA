#include <bits/stdc++.h>
using namespace std;
// DIVIDE AND CONQUER
// flow
// given l and r , check if l<r and
// cut the arry into two parts , call merge sort on both
// after they are sorted , call merge on them

// in merge
// declare two arrays of size mid-l+1 and r-mid , temp arrays to store the sorted arrays
// we will merge these two arrays now
// merge and store it in the original array

// IN C++ ARRAYS ARE PASSED BY REFERENCE BY DEFAULT
// WHEN U R PASSING A ARRAY YOU ARE PASSING THE POINTER TO THE FIRST ELEMENT OF THE ARRAY
void merge1(int arr[], int l, int mid, int r)
{
    // if odd then we will take more elements in n1 only , so it works out, if even we will do equal ,
    
    const int n1 = mid - l + 1;  // we are storing l to mid in the first array , but then we want a solid number so we take +1
    const int n2 = r - mid; // and here we are storing mid+1 to r , so actually it should be r-(mid+1) , but we need size so mid happened

    // summary is that we are storing l to mid in first and mid+1 to r in second array 
    // and we are making a sorted array of l to r ........
    int a1[n1];
    int a2[n2];
    for (int i = 0; i < n1; i++)
    {
        a1[i] = arr[i + l];
    }
    for (int i = 0; i < n2; i++)
    {
        a2[i] = arr[i + mid + 1];
    }
    int i = 0; //in the tempo arrays
    int j = 0;
    int k = l; //k iterates in the real array
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
        {
            arr[k] = a1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = a1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = a2[j];
        j++;
        k++;
    }



}



void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;// temporary array
    int left = low;// starting index of left half of arr
    int right = mid + 1;// starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements on the left half are still left //
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr //
    for (int i = 0; i < temp.size(); i++) {
        arr[i+low] = temp[i];
    }
}
void mergesort(vector<int>&arr, int l, int r)
{
    if (l < r) 
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    vector<int>arr = {209, 120, 1400, 230, 345, 450};
    mergesort(arr, 0, 5);
    cout << "merge sorted array" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// divide and conquer ...
// we will find mid then call merge sort on right and left of mid
// #include<iostream>
// using namespace std;
// void merge(int arr[],int l,int mid,int r)// we are merging two sorted arrays into 1 sorted array using two pointer method
// {
//     int n1=mid-l+1;
//     int n2=r-mid;
//     int a[n1];
//     int b[n2];//temp arrays
//     for(int i=0;i<n1;i++)
//     {
//         a[i]=arr[l+i];
//     }
//     for(int i=0;i<n2;i++)
//     {
//         b[i]=arr[mid+1+i];
//     }
//     int i=0;
//     int j=0;
//     int k=l;
//     while(i<n1 && j<n2)
//     {
//         if(a[i]<b[j])
//         {
//             arr[k]=a[i];
//             k++;i++;
//         }
//         else
//         {
//             arr[k]=b[j];
//             k++;j++;
//         }
//     }
//     while(i<n1)
//     {
//         arr[k]=a[i];
//         i++;k++;
//     }
//     while(j<n2)
//     {
//         arr[k]=b[j];
//         j++;k++;
//     }
// }
// void mergesort(int arr[],int l,int r)
// {
//     if(l<r)//if l==r then only one element is there in array not needed 2 are needed
//     {
//         int mid = (l+r)/2;
//         mergesort(arr,l,mid);
//         mergesort(arr,mid+1,r);
//         merge(arr,l,mid,r);
//     }
// }
// int main()
// {
//     int arr[]={209,120,1400,230,345,450};
//     mergesort(arr,0,5);
//     cout<<"merge sorted array"<<endl;
//     for(int i=0;i<6;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }
// TIME COMPLEXTIY
// RECURRENCE:
// T(N)=2T(N/2)+N
// T(N/2)=2T(N/4)+N/2
// T(N/4)=2T(N/8)+N/4
// .
// .
// T(1)=1
// K=LOG(N) NUMBER OF LEVELS
// T(N)= N+N+N+N+N........LOGN TERMS
// SO COMPLEXITY = NLOGN BRUH