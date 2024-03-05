// longest common substring
#include <bits/stdc++.h> 
using namespace std;
int solve(string x,string y,int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    else
    {
        if(x[n-1]==y[m-1])
        {
            return 1+solve(x,y,n-1,m-1);
        }
        else
        {
            return 0;
        }
    }
}
int main(){
    cout<<solve("abcde","ababcde",5,7);
return 0;
}


//memoized
#include <bits/stdc++.h> 
using namespace std;
int solve(string x, string y, int n, int m, vector<vector<int>>& dp) {
    if (n == 0 || m == 0) {
        return 0;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    if (x[n - 1] == y[m - 1]) {
        dp[n][m] = 1 + solve(x, y, n - 1, m - 1, dp);
    } else {
        dp[n][m] = 0;
    }
    return dp[n][m];
}

int main() {
    string x = "abcde";
    string y = "ababcde";
    int n = x.size();
    int m = y.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    int result = solve(x, y, n, m, dp);
    cout << result << endl;

    return 0;
}


// bottom up approach tabular
int longestCommonSubstring(string x, string y) {
    int n = x.size();
    int m = y.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0; // Variable to keep track of the maximum substring length.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]); // Update maxLen if a longer substring is found.
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return maxLen;
}
int main() {
    string x = "abcde";
    string y = "ababcde";

    int result = longestCommonSubstring(x, y);
    cout << result << endl;

    return 0;
}

