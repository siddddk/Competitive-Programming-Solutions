#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n; cin >> n;
    ll a[n];
    vector<ll> v;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> prefix;
    prefix.PB(0);
    ll ans = n;
    for(ll i = 1; i < n; i++) {
        prefix.PB(min(a[i] - 1, prefix[i - 1] + 1));
    }
    for(ll i = 0; i < prefix.size(); i++) {
        ans += prefix[i];
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