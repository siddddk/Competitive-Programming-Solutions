#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void solve(void) 
{
    ll n, c; cin >> n >> c;
    vector<pair<ll, ll>> a(n);
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = {x + min(n - i, i + 1), i + 1 + x};
    }
    sort(all(a));
    vector<ll> pref;
    pref.PB(0);
    for(ll i = 0; i < n; i++) {
        pref.PB(pref.back() + a[i].F);
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ll coins = c - a[i].S;
        ll l = 0, r = n;
        ll mx = 0;
        while(l <= r) {
            ll mid = (l + r) / 2;
            ll price = pref[mid];
            ll now = mid + 1;
            if(mid > i) {
                price -= a[i].F;
                now--;
            }
            if(price <= coins) {
                mx = max(now, mx);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ans = max(ans, mx);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}