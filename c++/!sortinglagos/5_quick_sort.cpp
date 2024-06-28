// flow , in the quick sort function
// take a pivot , call partition on it to find its correct position in the array
// all the bigger elements to the right
// all the lesser elements to the left
// then call quick sort for left to pivot-1 and pivot+1 to right
#include <bits/stdc++.h> 
using namespace std;

int partition(int arr[],int l,int r)
{
    int p=arr[r];
    int i=l-1; // here i is defined as the last element in arr which is less than pivot ,we will maitain this throughout  IMPORTANT TO UNDERSTAND
    // all the elements less than the pivot will be stored till i
    for(int j=l;j<r;j++)
    {
        if(arr[j]<p)
        {
            i++;
            // swapping ith element and jth element as till i we are storing the elements lesser than pivot
            int temp = arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    // swapping pivot element into its correct place
    int temp  = arr[r];
    arr[r]=arr[i+1];
    arr[i+1]=temp;
    return i+1;
}

void quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        int p = partition(arr,l,r);
        quicksort(arr,l,p-1);
        quicksort(arr,p+1,r);
    }
}


int main()
{
    int arr[] = {209, 120, 1400, 230, 345, 450};
    quicksort(arr, 0, 5);
    cout << "quick sorted array" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
//  swapping without using temporary variable
// x = x+y 10+20
// y= x-y 20  
// x= x-y 