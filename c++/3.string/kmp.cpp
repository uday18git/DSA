// prefix function
// prefix[i] is the length of the longest proper prefix of the substring 
// s[0...i] which is also the suffix of this substring . By definition prefix[0]=0;
// prefix[i] = maximum k such that 
// s[0..k-1] = s[i-(k-1)...i]

// for example
// s = "abcabcd"
// prefix array: [0,0,0,1,2,3,0];
#include<bits/stdc++.h>
using namespace std;
// vector<int> prefix_function(string s)
// {
//     int n=s.length();
//     vector<int> pi(n);
//     for(int i=0;i<n;i++)
//     {
//         for(int k=0;k<=i;i++)
//         {
//             if(s.substr(0,k)==s.substr(i-k+1,k))
//                 pi[i]=k;
//         }
//     }
//     return pi;

// }

vector<int> prefix_function(string s)
{
    int n=s.size();
    vector<int> pi(n,0);
    for(int i=1;i<n;i++)
    {

        
        int j=pi[i-1]; // till now how much prefix and suffix have matched in the current substring till i
    
        while(j>0 && s[i]!=s[j]) // if it doesnt match we keep making the j go back
        {
            j=pi[j-1];
        }
        if(s[i]==s[j]) //s[i] is checking suffix, s[j] is checking prefix if the next one also matches 
            j++; 
        pi[i]=j;
    }
    return pi;
    // Time complexity = O(n) (there is while loop , still how is it O(n) , because we are increasing till O(n) only , it will decrease also till first element of pi only so )
}
int main()
{
    string s="na";
    vector<int> res=prefix_function(s);
    string t="apnacollege";
    int pos=-1;
    int i(0),j(0);
    while(i<t.size())// we are iterating through t
    {
        if(t[i]==s[j])// if they are same iterate forward
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=res[j-1];
            }
            else
            {
                i++;
            }
        }
        if(j==s.size())
        {
            pos=i-s.size();
            break;
        }
    }
    cout<<pos;
    return 0;
}
// time complexity O(s+t)