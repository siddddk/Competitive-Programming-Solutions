#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n; cin >> n;
    vector<ll> a(n, 0);
    for(ll i = 0; i < n; i++) cin >> a[i];
    vector<ll> prefix(n, 0);
    prefix[0] = a[0];
    for(ll i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    ll ans = 1;
    for(ll i = 0; i < n - 1; i++) {
        ans = max(ans, __gcd(prefix[i], prefix[n - 1]));
    }
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