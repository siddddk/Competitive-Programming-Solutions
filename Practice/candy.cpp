#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;

bool likes[17][17];

void solve(void)
{
    ll n; cin >> n;
    ll dp[(1 << n)];
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            ll x; cin >> x;
            likes[i][j] = (x == 1);
        }
    }
    ll mask = (1 << n) - 1;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(ll i = 0; i < mask; i++) {
        ll k = __builtin_popcount(i);
        for(ll j = 0; j < n; j++) {
            if(likes[k][j] && !(i & (1 << j))) dp[i | (1 << j)] += dp[i];
        }
    }
    cout << dp[mask] << "\n";
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