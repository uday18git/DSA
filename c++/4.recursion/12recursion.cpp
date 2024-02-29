#include<iostream>
#include<string.h>
// 7 best problems on recursion itseems
// to print reverse of a given string using recursion
using namespace std;
void rev(string s1)
{
    if(s1.length()==0)
    {
        return;
    }
    rev(s1.substr(1));
    cout<<s1[0];
}
// to insert value of pi in each place where pi is present in a string
void replacePi(string s1)
{
    if(s1.empty())
    {
        return ;
    }
    if(s1[0]=='p' && s1[1]=='i')
    {
        cout<<"3.14";
        replacePi(s1.substr(2));
    }
    else
    {
        cout<<s1[0];
        replacePi(s1.substr(1));
    }
}
void pi(string s1)
{
    if(s1.find("pi")==std::string::npos)
    {
        cout<<s1<<endl;
        return;
    }
    int x= s1.find("pi");
    s1.erase(x,2);
    s1.insert(x,"3.14");
    pi(s1);
}



// remove all the duplicates of a string
// "aaaaaaabbbbbeeeeeeedddddddd" -> "abed"
string remDuplicate(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch = s[0];
    string ans=remDuplicate(s.substr(1));
    if(ch==ans[0])
    {
        return ans;
    }
    else
    {
        return ch+ans;
    }
}
string moveX(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch = s[0];
    string ans = moveX(s.substr(1));
    if(ch=='x')
    {
        return ans+ch;
    }
    else
    {
        return ch+ans;
    }
}
// generate substrings of a string  there will be 8 of these
// draw the recursive tree
// input output method bro
void subSeq(string s,string ans)
{
    if(s.length()==0) //when "input" becomes empty well get one ans
    {
        cout<<ans<<endl;
        return ;
    }
    char ch = s[0];
    string ros = s.substr(1);
    subSeq(ros,ans);
    subSeq(ros,ans+ch);

}
//ip oup method
void subSeqAscii(string s, string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    subSeqAscii(ros,ans);
    subSeqAscii(ros,ans+ch);
    subSeqAscii(ros,ans+ string(code));
}
// ADVANCED RECURSION PROBLEMS I
// print all permutations of ABC
void permutations(string s,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        string ros = s.substr(0,i)+s.substr(i+1);
        permutations(ros,ans+ch);
    }
}
// permutations with space 
void permutationsWithSpace(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<endl;
        return;
    }
    char ch = ip[0];
    string op1 = op + " "+ch;
    string op2 = op + ch;
    string ros = ip.substr(1); //ros means rest of string
    permutationsWithSpace(ros,op1);  
    permutationsWithSpace(ros,op2);  
}
void permutationWithCaseChange(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<endl;
        return; 
    }
    char ch = ip[0];
    char up = toupper(ch);
    permutationWithCaseChange(ip.substr(1),op+ch);
    permutationWithCaseChange(ip.substr(1),op+up);
}

// permutations in array leetcode
// class Solution {
// public:
//     vector<vector<int>> ans;
//     void perm(vector<int>& nums,int idx)
//     {
//         if(idx == nums.size())
//         {
//             ans.push_back(nums);
//             return ;
//         }
//         for(int i=idx;i<nums.size();i++)
//         {
//             swap(nums[i],nums[idx]);
//             perm(nums,idx+1);
//             swap(nums[i],nums[idx]);
//         }
//     }
    // void perm(vector<int>nums,vector<int>a)
    // {
    //     if(nums.size()==0)
    //     {
    //         ans.push_back(a);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         int num = nums[i];
    //         vector<int> roa ;
    //         for(int i=0;i<nums.size();i++)
    //         {
    //             if(nums[i]==num)
    //             {
    //                 continue;
    //             }
    //             roa.push_back(nums[i]);
    //         }
    //         roa.push_back(num);
    //         perm(nums,roa);
    //     }
    // } 
    
//     vector<vector<int>> permute(vector<int>& nums) {
//         perm(nums,0);
//         return ans;
//     }
// };
// count the number of paths possible from a start point to a end point in a game board
// 0 1 2 3 
// consider the above gameboard , consider s as 0 and e as 3 
// number of possible ways to go from s to e is , num of ways from s+1 to e plus num of ways from s+2 to e and so on till it reaches e
int countPath(int s , int e)
{
    if(s==e)
    {

        return 1;
    }
    if(s>e)
    {
        return 0;
    }
    int count =0;
    for(int i=1;i<=6;i++)
    {
        count+=countPath(s+i,e);
    }
    return count;
}
// number of paths in maze
int countPathMaze(int n,int i,int j)
{
    if(i==n-1 && j==n-1)
    {
        return 1;
    }
    if(i>n-1 || j>n-1)
    
    {
        return 0;
    }

    return countPathMaze(n,i+1,j) + countPathMaze(n,i,j+1);


}
//tiling problem
//given a 2*n board and given 2*1 tile , count number of ways to tile the given board using these tiles
// in how many ways can you fit a 2x1 in 2x4
// you can put it in horizontal way and vertical way 
// if we place vertically 
int tilingWays(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return tilingWays(n-1) + tilingWays(n-2); //looks like fibonacci
}

// friends pairing problem
// find the number of ways in which n friends can remain single or can be paired up
int friendsPairing(int n)
{
    if(n==0||n==1||n==2) // if n is 0 then there is only 0 , if n is 1 we can only leave him single , if n is 2 we can either pair them or leave them single
    {
        return n;
    }
    return friendsPairing(n-1) + friendsPairing(n-2)*(n-1);
}

// 01 knapsack problem
// put n items with given weight and value in a knapsack of capacity W to get maximum total value in the knapsack
// for all items i have 2 options take it or not

// this is without dp , because we did not store anything
int knapsack(int value[],int weight[],int n,int W)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(weight[n-1]>W)
    {
        return knapsack(value,weight,n-1,W);
    }
    return max(knapsack(value,weight,n-1,W-weight[n-1])+value[n-1],knapsack(value,weight,n-1,W));
}
int main()
{
    // rev("uday");
    // pi("piiiiiipiiiiiipi");
    // replacePi("piiiiiipiiiiiipi");
    // towerOfHanoi(2,'A','C','B');
    // cout<< remDuplicate("aaaaaaabbbbbeeeeeeedddddddd");
    // cout<<moveX("xasdaxsadaxasdaxadsax");
    // subSeq("AB","");
    // subSeqAscii("AB","");
    // permutations("ABC","");
    // string ip = "BC";
    // string op = "A";
    // permutationsWithSpace(ip,op);
    permutationWithCaseChange("ab","");
    // cout<<countPath(0,3);
    // cout<<countPathMaze(3,0,0)<<endl;
    // cout<<tilingWays(3);
    // cout<<friendsPairing(4)<<endl;
    // int wt[] = {10,20,30};
    // int val[]= {100,50,150};
    // int W = 50;
    // cout<<knapsack(val,wt,3,W); 
    return 0;
}
