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
    ll n; cin >> n;
    vector<ll> a (n, 0);
    for(ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = n / 2;
    for(ll i = 0; i < n - 1; i++) {
        if(a[i] != a[i + 1]) {
            ans = max(ans, (i + 1)*(n - i - 1));
        }
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