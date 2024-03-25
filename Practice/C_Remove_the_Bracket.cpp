#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;
ll dp[200005][2];

void solve(void)
{
    ll n, s; cin >> n >> s;
    vector<ll> a (n, 0);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vector<pair<ll, ll>> splits;
    splits.PB({a[0], a[0]});
    for(ll i = 1; i < n - 1; i++) {
        if(a[i] > s) splits.PB({s, a[i] - s});
        else splits.PB({0, a[i]});
    }
    splits.PB({a[n - 1], a[n - 1]});
    dp[0][0] = dp[0][1] = 0;
    for(ll i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0] + splits[i - 1].S * splits[i].F, dp[i - 1][1] + splits[i - 1].F * splits[i].F);
        dp[i][1] = min(dp[i - 1][0] + splits[i - 1].S * splits[i].S, dp[i - 1][1] + splits[i - 1].F * splits[i].S);
    }
    cout << dp[n - 1][0] << "\n";
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