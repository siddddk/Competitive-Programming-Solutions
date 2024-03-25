#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;


void solve(void)
{
    string s1, s2; cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    int k = min(n, m);
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 0; i <= n; i++) dp[i][m] = n - i;
    for(int i = 0; i <= m; i++) dp[n][i] = m - i;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(s1[i] == s2[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
            else dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
        }
    }
    cout << dp[0][0] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}