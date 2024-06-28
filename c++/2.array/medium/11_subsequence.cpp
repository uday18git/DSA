// 2486. Append Characters to String to Make Subsequence

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.length();
        int m=t.length();
        int i=0;
        int j=0;
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return m-j;
    }
};


// class Solution {
// public:
//     int appendCharacters(string s, string t) {
//         int n=s.length();
//         int m=t.length();
//         int i=0,j=0;
//         while(i<m && s[i]==t[j])
//         {
//             i++;
//             j++;
//         }
//         int ans=i;
//         i=n-1;
//         j=0;
//         while(i>=0 && j<m && s[i]==t[j])
//         {
//             ans--;
//             i--;
//             j++;
//         }
//         return ans;
//     }
// };


// mis understanding that lcs
// class Solution {
// public:
//     int lcs(string s1, string s2, int n, int m, vector<vector<int>>& dp) {
//         if (n == 0 || m == 0) {
//             return 0;
//         }
//         if (dp[n][m] != -1) {
//             return dp[n][m];
//         }
//         if (s1[n - 1] == s2[m - 1]) {
//             return dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1, dp);
//         } 
        
//     }

//     int appendCharacters(string s, string t) {
//         int m = s.length();
//         int n = t.length();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//         int ans = lcs(s, t, m, n, dp);
//         cout << ans;
//         ans = n - ans;
//         return ans;
//     }
// };