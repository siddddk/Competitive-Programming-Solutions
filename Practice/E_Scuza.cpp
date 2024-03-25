#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, q; cin >> n >> q;
    vector<ll> a (n, 0), height (n + 1, 0);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    height[1] = a[0];
    for(ll i = 2; i <= n; i++) {
        height[i] = height[i - 1] + a[i - 1];
    }
    vector<ll> maxJump (n, 0);
    ll m = a[0];
    maxJump[0] = a[0];
    for(ll i = 1; i < n; i++) {
        m = max(m, a[i]);
        maxJump[i] = m;
    }
    // for(ll i = 0; i < n; i++) cout << maxJump[i] << " ";
    // cout << "\n";
    for(ll i = 0; i < q; i++) {
        ll k; cin >> k;
        auto it = upper_bound(maxJump.begin(), maxJump.end(), k);
        cout << height[it - maxJump.begin()] << " ";
    }
    cout << "\n";
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