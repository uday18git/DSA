// https://chatgpt.com/share/c7b30375-6caf-4ca6-ad1f-4ff214dfaae8
#include<bits/stdc++.h>
using namespace std;
// basic
// first occurance of an elemnt , 
while(start <= end) // when this while loop will break start will be at the first occurance of the target, its magic
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
    cout << start << endl; // u will return start

// u will let it run till start<=end is true

// LAST OCCURANCE OF AN ELEMENT
while(start <= end) // when this while loop will break end will be at the last occurance of the target, its magic
{
    int mid = start + (end - start) / 2;
    if (arr[mid] <= key)
    {
        start = mid + 1;
    }
    else
    {
        end = mid - 1;
    }
}
cout << end << endl; // instead of returning this you can store it also


// count of an element in sorted array
// sorted is given so we can do in binary search
// first occurance - last occurance  is coming to my mind
// correct


// FLOOR AND CIEL , FLOOR IS THE HIGHEST NUMBER THAT IS LESS THAN THE NUMBER
//  CIEL IS THE LOWEST NUMBER THAT IS HIGHER THAN THE NUMBER

int main()
{
    vector<int>arr={1,2,3,4,8,10,10,12,19};
    int key=20;
    int low=0;
    int n=arr.size();
    int high=n-1;

    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid]<key)
        {
            low=mid+1;
        }
        else 
        {
            high=mid-1;
        }
    }
    return high;
}


// ciel

int main()
{
    return low;
}



// n - number of pages in n different books (ascending order)
// m - number of students
// All the books have to be divided among m students consecutively. 
// Allocate the pages in such a way that 
// maximum pages allocated to a student is minimum.
// pages = [12,34,67,90]
// students(m) = 2
// different possiblities
// [12][34,67,90] - 191
// [12,34][67,90] - 157
// [12,34,67][90] - 113 most optimal solution
//
// STRATEGY
// IN THESE PROBLEMS IMPORTANT TO THINK THROUGH THE RANGE OF START AND END VERY CAREFULLY !!!!!!!!!!!!!!!!!!!!!!!

#include<climits>
#include<iostream>
using namespace std;
// min is the number we are finding basically (mx or mid)
bool isPossible(int arr[],int n,int m,int min)
{
    int studentsRequired=1,sum=0;
    for(int i=0;i<n;i++)
    {
        // if(arr[i]>min) //not possible
        // {
        //     return false;
        // }
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
    int start = arr[n-1],end=sum,ans=INT_MAX; // start with arr[n-1] because some students has to take the arr[n-1] book  so that is the least minimum possible maximum pages that a student can get
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


// PEAK ELEMENT
// HERE ARRAY NEED NOT BE SORTED
#include "bits/stdc++.h"
using namespace std;
// TO FIND OUT PEAK ELEMENT .. PEAK ELEMENT MEANS IT SHOULD BE GREATER THAN PREVIOUS AND NEXT ELEMENT
// STRATEGY
// COMPUTE MID , SEE IF ARR[MID]> ARR[MID+1] && ARR[MID]>ARR[MID-1],,,,,,,, ELSE IF ARR[MID-1]>ARR[MID] CHECK LEFT BECAUSE THAT CAN BE A PEAK RIGHT
int findPeakElement(int arr[],int low,int high,int n)
{
    int mid= high+(low-high)/2;
    if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1]))return mid;
    else if(mid>0 && arr[mid] < arr[mid-1])return findPeakElement(arr,low,mid-1,n);//MID>0 TO MAKE SURE THAT MID-1 IS NON NEGATIVE
    else return findPeakElement(arr,mid+1,high,n);
}

// BELOW READ!!  , there can be multiple peak elements btw
int main()
{
    int arr[] = {0,6,8,5,7,9};
    int n=6;
    // cout<<"Peak element index : "<<findPeakElement(arr,0,n-1,n)<<endl;

    int high=n-1;
    int low=0;
    while(high>=low)
    {
        int mid = (high+low)/2;
        if((mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1])) 
        {
            cout<<" Found peak at: "<<arr[mid]<<endl;
            break;
        }
        else if(mid>0 && arr[mid]<arr[mid-1]) // THIS IS THE MAIN LOGIC , THAT IF MID<MID-1 , THEN WE WILL FIND THE PEAK ELEMENT LEFT SIDE , BECAUSE AFTER MID-1>MID , EITHER MID-1'S LEFT HAS TO BE GREATER OR SMALLER , EITHER AND IF WE GET A SMALLER THAT IT SELF IS THE PEAK ELEMENT.. SO 
        {
            high=mid-1;
        }
        else // IF MID+1 IS > MID , THEN WE WILL FIND THE PEAK ELEMENT AT THE RIGHT
        {
            low=mid+1;
        }
    }

    return 0;
}

// NUMBER OF TIMES A SORTED ARRAY IS ROTATED .......
// nothing but index of minimum number

// when mid is calculated , one side of mid is sorted and another side is unsorted

// we will find the minimum element in the unsorted part
// when array is sorted arr[start]<=arr[end] then start is the answer
// we can identify the unsorted part , arr[start]<=arr[mid] then left part is sorted and
// right part is unsorted , so we will search in right part
// start=mid+1 we will do
// else if arr[mid]<=arr[end] then right part is sorted and left part is unsorted , so we will search in left part
// end=mid-1 we will do
#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int> arr ={4,5,6,7,0,1,2}; //{11,12,15,18,2,5,6,8};
    int start=0;
    int end=arr.size()-1;
    int n=arr.size();
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        // if(arr[mid]<=arr[(mid-1+n)%n] && arr[mid]<=arr[(mid+1)%n])
        if((mid==0 || arr[mid-1]>=arr[mid]) && (mid==n-1 || arr[mid]<=arr[mid+1]))
        {
            cout<<mid;
            break;
        }
        else if(arr[start]<=arr[end]){
	            cout<<start;
                break;
	        }
        else if(arr[start]<=arr[mid])
        {
            start=mid+1;
        }
        else if(arr[mid]<=arr[end])
        {
            end=mid-1;   
        }
    }   

return 0;
}


// SEARCH IN ROTATED SORTED ARRAY
// we have to see 2 cases if left is sorted 
// if right is sorted
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]==target)return mid;
            // left sorted
            else if(nums[start]<=nums[mid])
            {
                // left is sorted and left has the target , so we eliminate right and search left
                if(nums[start]<=target && target<=nums[mid])
                {
                    end=mid-1;
                }
                // left is sorted but doesnt have the target , eliminate left so we search right
                else
                {
                    start=mid+1;
                }
            }
            // right sorted
            else if(nums[mid]<=nums[end])
            {
                // right is sorted and has the target , so we eliminate left and search right
                if(nums[mid]<=target && target<=nums[end])
                {
                    start=mid+1;
                }
                // right is sorted and doesnt have the target so we elminate right and search left
                else
                {
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};

// search in a nearly sorted array
// heree ,  a element that has to be in the ith position , can be in i+1 or i-1th position
#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int> arr={5,10,30,20,40};
    int key=20;
    int start=0,end=arr.size()-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            cout<<mid;
            break;
        }
        if(arr[mid-1]==key)
        {
            cout<<mid-1;
            break;
        }
        if(arr[mid+1]==key)
        {
            cout<<mid+1;
            break;
        }
        else if(arr[mid]>key)
        {
            end=mid-2;// because its a nearly
        }
        else 
        {
            start=mid+2;
        }
    }
return 0;
}


// single element in a sorted array

// {1,1,2,2,3,3,4,5,5,6,6} => 4

// (even,odd) for the elements left to the single element
// (odd,even) for the elements right to the single element
// IMPORTANT -> DOWN LINES
// so for two same elements if the index is even odd then the single element is on the right side, eliminate the left side
// if the index is odd even then the single element is on the left side , eliminate the right side
// and also the single element is only element which is not equal to next and previous element
// suppose we are writing this above line condition, there are many edge cases to handle , so
// in binary search problems where many edge cases have to be handled , we have to remove / eliminate those (shrink the search space)
// take low=1, high=n-2
// so below i am checking for edge cases seperately and searching in the rest of the array
// f(arr,n)
// if(n==1)return arr[0];
// if(arr[0]!=arr[1])return arr[0];
// if(arr[n-1]!=arr[n-2])return arr[n-1];

// OR INSTEAD OF ABOVE TWO LINES U CAN CHECK IN THE IF CONDITION ITSELF mid==0 || , mid==n-1 ....... like we did for the above problems
// just because it can go out of bound if we check mid-1 , mid+1 , they are doing all this bs 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int start=1;
        int end=n-2;   
        if(n==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])return nums[mid];
            // if u r in the left half, ur either on the even index or odd index
            // element is in the right side, so we have to eliminate the left half
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1]))
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return -1;
        
    }
};
