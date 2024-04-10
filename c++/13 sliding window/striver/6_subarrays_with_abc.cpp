class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen = {-1,-1,-1};
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1)
            {
                count+=(1+min(lastSeen[0],min(lastSeen[1],lastSeen[2])));
            }
        }
        return count;
    }
};



// brute force would be to 
// check all subarrays and if it has all 3 characters , we add the answer the length of the rest of the array , because we can take all of them and the condition will still satisfy


// my flopped soln
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n=s.size();
//         int r=0;
//         int l=0;
//         int countA=0;
//         int countB=0;
//         int countC=0;
//         int ans=0;
//         while(r<n)
//         {
//             if(s[r]=='a')countA++;
//             if(s[r]=='b')countB++;
//             if(s[r]=='c')countC++;
//             while(countA && countB && countC)
//             {
//                 if(s[l]=='a')countA--;
//                 if(s[l]=='b')countB--;
//                 if(s[l]=='c')countC--;
//                 l++;
//                 ans++;
//             }
//             r++;
//         }
//         return ans;
//     }
// };