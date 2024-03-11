class Solution {
public:
    
    bool compare(string &big, string &small) {
        if (big.size() != small.size() + 1) // Difference in size should be exactly 1
            return false; 
        
        int i = 0, j = 0;
        int n = big.size(), m = small.size();
        bool mismatch = false; // Flag to check if there is a mismatch
        while (i < n && j < m) {
            if (big[i] == small[j]) {
                i++;
                j++;
            } else {
                if (mismatch) // If there is already a mismatch, return false
                    return false;
                mismatch = true; // Mark a mismatch
                i++; // Move pointer in bigger word
            }
        }
        return true; // If we reached here, it means one character difference was found
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (compare(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

// tell me the case where my compare function does not work
// ChatGPT
// Sure, let's consider the case where your original compare function fails:

// cpp
// Copy code
// compare("pcxbcf", "pcxbc")
// In this case, the larger word is "pcxbcf" and the smaller word is "pcxbc". 
// The size difference is exactly 1, so according to your function, it should return true. 
// However, this is incorrect because the smaller word "pcxbc" can't be obtained from "pcxbcf" by just removing one character.
//  In fact, "pcxbc" can be obtained from "pcxbcf" by removing "f" and inserting "c" before "b", so the function should return false in this case.






// class Solution {
// public:
    
//     bool compare(string &big,string &small)
//     {

//         if(big.size()<small.size() || big.size()!=small.size()+1)return false; 
//         int i=0;
//         int j=0;
//         int n=big.size();
//         int m=small.size();
//         while(i<n && j<m)
//         {
//             if(big[i]==small[j])
//             {
//                 i++;
//                 j++;
//             }
//             else 
//             {
//                 i++;
//             }
//         }
//         if(i==n && j==m)return true;
//         else return false;
//         // return j==m;
//     }
//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(),words.end(),[](const string &a, const string &b) {
//             return a.size() < b.size();});
//         int n=words.size();
//         vector<int> dp(n,1);
//         int ans=1;
//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(compare(words[i],words[j]) && dp[i]<dp[j]+1)
//                 {
//                     dp[i] = dp[j]+1;
//                 }
//             }
//             ans=max(dp[i],ans);
//         }
//         return ans;
//     }
// };
// this whole answer was for subsequences , but needed is subsets, according to the test case 2
// for this we need to sort the array using comparator based on size

// class Solution {
// public:
//     bool compare(string big,string small)
//     {

//         if(big.size()!=small.size()+1)return false; // important
//         // it needs to be 1 greater. . you missed this
//         int i=0;
//         int j=0;
//         int n=big.size();
//         int m=small.size();
//         while(i<n && j<m)
//         {
//             if(big[i]==small[j])
//             {
//                 i++;
//                 j++;
//             }
//             else 
//             {
//                 i++;
//             }
//         }
//         if(i==n && j==m)return true;
//         else return false;
//         // return j==m;
//     }
//     int longestStrChain(vector<string>& words) {
//         int n=words.size();
//         vector<int> dp(n,1);
//         int ans=1;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(compare(words[i],words[j]) && dp[i]<dp[j]+1)
//                 {
//                     dp[i] = dp[j]+1;
//                 }
//             }
//             ans=max(dp[i],ans);
//         }
//         return ans;
//     }
// };