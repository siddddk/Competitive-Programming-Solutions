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
    ll n, m; cin >> n >> m;
    vector<ll> a(n*m); cin >> a;
    ll mx = *max_element(all(a)), mn = *min_element(all(a)), cntmx = 0, cntmn = 0;
    ll mx2 = LLONG_MIN, mn2 = LLONG_MAX;
    for(ll i = 0; i < a.size(); i++) {
        if(a[i] == mx) cntmx++;
        if(a[i] == mn) cntmn++;
        if(a[i] != mx) {
            mx2 = max(mx2, a[i]);
        }
        if(a[i] != mn) {
            mn2 = min(mn2, a[i]);
        } 
    }
    if(cntmx >= 2 || cntmn >= 2) {
        cout << (n*m - 1)*(mx - mn) << "\n";
    }
    else {
        if((mx - mn2) >= (mx2 - mn)) {
            ll ans = (min(m, n) - 1)*(mx - mn2);
            ans += (n*m - (min(m, n))) * (mx - mn);
            cout << ans << "\n";
        }
        else {
            ll ans = (min(m, n) - 1)*(mx2 - mn);
            ans += (n*m - (min(m, n))) * (mx - mn);
            cout << ans << "\n";
        }
    }
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