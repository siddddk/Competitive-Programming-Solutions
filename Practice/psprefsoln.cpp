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
    int n, m; cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> a[i][j];
    }
    int dp[n][m];
    for(int i = 0; i < m; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i - 1][j] <= a[i][j]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = i;
        }
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for(int i = 0; i < n; i++) {
        int rowMin = dp[i][0];
        for(int j = 0; j < m; j++) {
            rowMin = min(rowMin, dp[i][j]);
        }
        dp[i][0] = rowMin;
    }
    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b; a--; b--;
        if(dp[b][0] <= a) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}