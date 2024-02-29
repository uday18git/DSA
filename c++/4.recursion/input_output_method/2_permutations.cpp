// // similar to subsets problem
// // ip oup method

#include <bits/stdc++.h> 
using namespace std;

//string
void permutations(string ip,string op)
{
    if(ip.size()==0)
    {
        cout<<op<<endl;
        return;
    }
    for(int i=0;i<ip.size();i++)
    {
        char temp = ip[i];
        string ros = ip.substr(0,i) + ip.substr(i+1); //why does this line work
        // ip = ip.substr(0,i) + ip.substr(i+1); does not work
        permutations(ros,op+temp);
    }
}

// for numbers
// It seems like you're trying to implement a function to generate permutations of a given vector of integers recursively. 
// The issue with your code is that you're not properly handling the creation of new vectors for each recursive call.
//  As you're passing the vector `a` by value, it's not getting reset properly, leading to incorrect results. 
// To fix this, you need to ensure that for each recursive call, a copy of the original vector `a` is passed rather than modifying the same vector. 
// Here's the corrected version of your code:


// With this adjustment, each recursive call receives its own copy of the vector `a`, 
// ensuring that modifications made to it don't affect other recursive calls, 
// and thus generating correct permutations.
void perm(vector<int>nums,vector<int>a,vector<vector<int>>&ans)
{
    if(nums.size()==0)
    {
        ans.push_back(a);
        
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        int num = nums[i];
        vector<int> roa;
        for(int j=0;j<nums.size();j++)
        {
            if(j==i)
            {
                continue;
            }
            roa.push_back(nums[j]);
        }
        vector<int> new_a = a; // Create a copy of 'a' for the current recursive call
        new_a.push_back(num);
        perm(roa, new_a, ans);
        
    }
}

// permutation with space
// // "_A_B_C"
// void permutationsWithSpace(string ip,string op)
// {
//     if(ip.length()==0)
//     {
//         cout<<op<<endl;
//         return;
//     }
//     char ch = ip[0];
//     string op1 = op + " "+ch;
//     string op2 = op + ch;
//     string ros = ip.substr(1); //ros means rest of string
//     permutationsWithSpace(ros,op1);  
//     permutationsWithSpace(ros,op2);  
// }

// //"A_B_C"
// // you have to initialise ip as bc and op as a




int main(){
    
    
    // permutationsWithSpace("abc","");
    // permutationsWithSpace("bc","a");

    //numbers
    vector<int> nums = {1,2,3};
    vector<int> a;
    vector<vector<int>> ans;
    perm(nums,a,ans);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
return 0;
}

