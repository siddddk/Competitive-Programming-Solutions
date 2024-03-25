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
    ll a, b; cin >> a >> b;
    ll n, m; cin >> n >> m;
    ll ans = min(n*a, n*b);
    ll aC = a, bC = b, mC = m, nC = n;
    if(((mC * a)) < min(a, b) * (m + 1)) {
        ll uses = max(1ll, (n / (m + 1)));
        // cout << "uses: " << uses << "\n";
        ll c = uses*a*m + max(n - uses*(m + 1), 0ll) * min(a, b);
        cout << min(c, ans) << "\n";
    }
    else {
        cout << ans << "\n";
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