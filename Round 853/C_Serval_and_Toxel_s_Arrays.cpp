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

void solve(void) {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), p(m), v(m), nums(n + m + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        nums[a[i]] += m + 1;
    }
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        cin >> p[i] >> v[i];
        p[i]--;
        nums[a[p[i]]] -= (m - i);
        a[p[i]] = v[i];
        nums[v[i]] += (m - i);
    }
    ans = (m + 1) * m * n;
    for(auto x : nums) {
        ans -= (x * (x - 1)) / 2;
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