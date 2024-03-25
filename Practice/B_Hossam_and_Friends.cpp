#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, m; cin >> n >> m;
    vector<ll> a (n + 1, 0);
    for(ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        if(x < y) {
            a[y] = max(a[y], x);
        }
        else {
            a[x] = max(a[x], y);
        }
    }
    vector<ll> dp(n + 1, 0);
    ll ans = n;
    for(ll i = 1; i <= n; i++) {
        dp[i] = min(i - a[i] - 1, dp[i - 1] + 1);
        ans += dp[i];
    }   
    // for(ll i = 0; i < n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}