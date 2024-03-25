#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;
ll dp[(1 << 20) + 1];

ll rec(ll mask, ll n) {
    if(mask == ((1 << n) - 1)) return 1;
    if(dp[mask] == -1) {
        ll ans = 0;
        for(ll i = 0; i < n; i++) {            
            if((mask & (1 << i)) == 0) {
                bool flag = true;
                for(ll j = 0; j < n; j++) {
                    if((mask & (1 << j)) != 0) {
                        if(((j + 1) & (i + 1)) == (i + 1)) {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag) {
                    ans += rec((mask | (1 << i)), n);
                } 
            }
        }
        dp[mask] = ans;
    }
    return dp[mask];
}

void solve(void)
{
    ll n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}