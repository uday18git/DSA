// things used 
// map.find();
// swap(a[i],a[j]); to swap in vector 

// to find the largest
// nothing fancy
// brute force will be to sort it and last number
// optimal will be to do a pass

// to find second largest
// brute force will be to sort and do a pass from back to find the second largest
// better will be to do two passes , one for largest and other for second largest
// optimal will be to do a pass , if largest gets updated then update the second largest as the previous largest
#include<bits/stdc++.h>
using namespace std;
vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here
    int largest=-1;
    int secondlargest;
    int smallest=INT_MAX;
    int secondsmallest;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>largest)
        {
            secondlargest=largest;
            largest=a[i];
        }
        if(a[i]<smallest)
        {
            secondsmallest=smallest;
            smallest = a[i];
        }
        if(a[i]>smallest && a[i]<secondsmallest) // IMPORTANT TO CONSIDER
        {
            secondsmallest=a[i];
        }
        if(a[i]<largest && a[i]>secondlargest) 
        {
            secondlargest=a[i];
        }
    }
    return {secondlargest,secondsmallest};
}




// to see if it is sorted or not, simple one pass nothing complex
// remove duplicates from a SORTED array
// we will maintain a variable 
// then increment the varaible to keep storing new and ignore duplicates
// similar approach we use in move zeros to the last 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) {
            return n;
        }
        
        int ans = 1; // The first element is always unique
        
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[ans] = nums[i]; // Overwrite duplicates
                ans++;
            }
        }
        return ans;
    }
};
//  nums.erase(nums.begin()+3) remove that element did not work
// nums.clear is to remove the whole array



// left rotate an array by one place
// store the first number , then left shift all other by one pass

// left rotate by D places
// you can store the first k elements 
// then shift the rest to starting 
// then put back the stored array at last
// !!!!!! important thing is to k=k%n if k>n;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> ans;
        int n=nums.size();
        if(n<=1)return ;
        if(k>=n)k%=n;
        for(int i=n-k;i<n;i++)
        {
            ans.push_back(nums[i]);
        }
        for(int i=0;i<n-k;i++)
        {
            ans.push_back(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=ans[i];
        }
        // return ans;
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int zeros=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i])
            {
                nums[ans]=nums[i];
                ans++;
            }
        }
        for(int i=n-1;i>=ans;i--)
        {
            nums[i]=0;
        }
    }
};

//  union  of 2 arrays
//  brute force 
//  using set datastructure
//  logn is the time taken to insert in set
//  time complexity is n1logn+n2logn + O(n1+n2) where n is size of set which is varying
//  space complexity = O(n1+n2) + O(n1+n2)
//  optimal Solution is to use two pointers, take the smaller one each time and see if ans.back() is not equal to the current element then push it back
//  after the loop ends , if one of the array is still left , then that will be greater so pushed back and same we have to check .back() element is not equal to the current element

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int n=a.size();
    int m=b.size();
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n && j<m)
    {
        if(a[i]<=b[j])
        {
            if(unionArr.size()==0 || unionArr.back()!=a[i]) // to make sure that there are no duplicates
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if(unionArr.size()==0 || unionArr.back()!=b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
        
    }
    while(i<n)
    {
       if(unionArr.back()!=a[i])
       {
            unionArr.push_back(a[i]);
       }
        i++;
    }
    while(j<m)
    {
        if(unionArr.back()!=b[j])
        {
                unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;
}


// intersection , present in both arrays
class Solution{
    public:
        vector<int> intersection(vector<int>a , vector<int> b)
        {
            int i=0;
            int j=0;
            vector<int>ans;
            if(a[i]<b[j])
            {
                i++;
            }
            else if(b[j]<a[i])
            {
                j++;
            }
            else
            {
                ans.push_back(a[i]);
                i++;
                j++;
            }
            return ans;
        }
}


// missing number of a array 
// expected sum - sum
// xor soln , xor


// maximum consecutive ones 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                while(i<n && nums[i]==1 )
                {
                    curr++;
                    i++;
                }
                ans=max(curr,ans);
            }
            curr=0;
        }
        return ans;
    }
};


// single number , one xor pass
