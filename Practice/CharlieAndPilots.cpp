#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;
int dp[501][501];

int rec(int n, vector<int>& c, vector<int>& a, int capt, int asst, int idx) {
    if(idx >= n) {
        return 0;
    }
    if(dp[capt][asst] == -1) {
        int ans;
        if(asst == n / 2) {
            ans = rec(n, c, a, capt + 1, asst, idx + 1) + c[idx];
        }
        else if(capt == asst) {
            ans = rec(n, c, a, capt, asst + 1, idx + 1) + a[idx];
        }
        else {
            ans = min(rec(n, c, a, capt, asst + 1, idx + 1) + a[idx], rec(n, c, a, capt + 1, asst, idx + 1) + c[idx]);
        }
        dp[capt][asst] = ans;
        return ans;
    }
    else return dp[capt][asst];
}


void solve(void)
{
    int n; cin >> n;
    vector<int> c (n, 0), a (n, 0);
    for(int i = 0; i < n; i++) {
        cin >> c[i] >> a[i];
    }
    for(int i = 0; i < 501; i++) {
        for(int j = 0; j < 501; j++) dp[i][j] = -1;
    }
    rec(n, c, a, 0, 0, 0);
    // for(int i = 0; i <= n/2; i++) {
    //     for(int j = 0; j <= n/2; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
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