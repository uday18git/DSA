// print shortest common supersequence
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // scs of this is geeke
    string a = "geek";
    string b = "eke";
    int m = a.length();
    int n = b.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // filling the table
    int i, j;
    for (i = 1; i < m + 1; i++)
    {
        for (j = 1; j < n + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    // now coming from bottom right to up and making our scs
    string scs = "";
    i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            scs.push_back(a[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                scs.push_back(a[i - 1]);
                i--;
            }
            else
            {
                scs.push_back(b[j - 1]);
                j--;
            }
        }
    }
    // IMPORTANTTTTTTTT
    while (i > 0)
    {
        scs.push_back(a[i - 1]);
        i--;
    }
    while (j > 0)
    {
        scs.push_back(b[j - 1]);
        j--;
    }


    reverse(scs.begin(), scs.end());
    cout << scs << endl;

    return 0;
}