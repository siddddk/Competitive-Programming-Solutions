#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> c;
    for(ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        c.push_back(make_pair(a, 1));
        c.push_back(make_pair(b, -1));
    }
    sort(c.begin(), c.end());
    ll cur = 0;
    ll ans = 0;
    for(auto x : c) {
        cur += x.second;
        ans = max(cur, ans);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}