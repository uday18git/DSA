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
