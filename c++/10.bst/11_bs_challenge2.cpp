//n - number of pages in n different books (ascending order)
//m - number of students
//All the books have to be divided among m students consecutively. Allocate the pages in such a way that maximum pages allocated to a student is minimum.
// pages = [12,34,67,90]
// students(m) = 2
// different possiblities
// [12][34,67,90] - 191
// [12,34][67,90] - 157
// [12,34,67][90] - 113 most optimal solution
//
// STRATEGY
// 
#include<climits>
#include<iostream>
using namespace std;



//min is the number we are finding basically (mx or mid)
bool isPossible(int arr[],int n,int m,int min)
{
    int studentsRequired=1,sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>min)
        {
            return false;
        }
        if(sum+arr[i]>min)//when the sum goes greater than the minimum possible maximum pages , more students are needed right..
        //and if this students go greater than students available(m) then return false..
        {
            studentsRequired++;
            sum=arr[i];
            if(studentsRequired>m)
            {
                return false;
            }
        }
        else// sum is less than the minimum possible maximum pages and adding next element also does not make it greater then simply add it
        {
            sum+=arr[i];
        }
    }
    return true;
}
// n (length of array basically) is the number of books .. m is number of students
int allocateMinimumPages(int arr[],int n,int m)
{
    int sum=0;
    if(n<m)return -1;//no point if number of students are more than number of books
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int start = arr[n-1],end=sum,ans=INT_MAX;
    while(start<=end)
    {
        int mid= start+(end-start)/2;//to avoid integer overflow
        if(isPossible(arr,n,m,mid))
        {
            ans = min(ans,mid);
            end = mid-1;//if it is possible we have to try to find a smaller one 
        }
        else
        {
            start = mid+1;//if not possible we have to try to find a bigger one
        }

    }
    return ans;
}
int main()
{
    int arr[]= {12,34,67,90};
    int n=4;
    int m=2;
    cout<<"The minimum number of pages : "<<allocateMinimumPages(arr,n,m)<<endl; //113 answer
    return 0;
}