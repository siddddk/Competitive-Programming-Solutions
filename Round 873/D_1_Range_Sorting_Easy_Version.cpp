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
    ll n; cin >> n;
    vector<ll> a(n); cin >> a; 

    vector<vector<ll>> mn(n + 1, vector<ll> (n + 1, LLONG_MAX));
    for(ll i = 0; i < n; i++) {
        for(ll j = i + 1; j <= n; j++) {
            mn[i][j] = min(mn[i][j - 1], a[j - 1]);
        }
    }
    ll ans = n * (n - 1) * (n + 1) / 6;
    for(ll m = 1; m < n; m++) {
        ll r = n;
        ll mx = -1;
        for(ll l = m - 1; l >= 0; l--) {
            mx = max(mx, a[l]);
            while(mx > mn[m][r]) {
                r--;
            }
            ans -= (r - m);
        }
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