#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

int rec(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++)
    {
        dp[i][n] = m - i;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[m][i] = n - i;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (word1[i] == word2[j])
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = min(dp[i][j + 1], min(dp[i + 1][j], dp[i + 1][j + 1])) + 1;
            }
        }
    }
    return dp[0][0];
}
int minDistance(string word1, string word2)
{
    return rec(word1, word2);
}

void solve(void)
{
    string word1, word2; cin >> word1 >> word2;
    cout << minDistance(word1, word2) << "\n"; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}