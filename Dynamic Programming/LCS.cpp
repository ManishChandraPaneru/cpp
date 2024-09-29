#include <bits/stdc++.h>
using namespace std;

//printLCS Definition
void printLCS(string s1,string s2, vector<vector<int>>&dp);
// RECURSION
int LCS(string s1, string s2, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (s1[i] == s2[j])
        return 1 + LCS(s1, s2, i - 1, j - 1);
    return 0 + max(LCS(s1, s2, i - 1, j), LCS(s1, s2, i, j - 1));
}

// MEMOIZATION
int LCSMemo(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + LCSMemo(s1, s2, i - 1, j - 1, dp);
    return dp[i][j] = 0 + max(LCSMemo(s1, s2, i - 1, j, dp), LCSMemo(s1, s2, i, j - 1, dp));
}

// TABULATION
void LCStabulate(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    printLCS(s1, s2, dp);
}

void printLCS(string s1, string s2, vector<vector<int>> &dp)
{
    int i = s1.size();
    int j = s2.size();
    vector<char> LCS;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            LCS.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(LCS.begin(), LCS.end());
    for (char c : LCS)
    {
        cout << c;
    }
    cout << endl;
}

int main()
{
    string str1 = "ABCBDAB", str2 = "BCDB";
    cout << "LCS using Recursion: " << LCS(str1, str2, str1.size() - 1, str2.size() - 1) << endl;
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, -1));
    cout << "LCS using Memoization: " << LCSMemo(str1, str2, str1.size() - 1, str2.size() - 1, dp) << endl;
    cout << "LCS using Tabulation: " << endl;
    LCStabulate(str1, str2);
    return 0;
}