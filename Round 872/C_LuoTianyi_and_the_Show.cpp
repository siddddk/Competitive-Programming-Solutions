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
    vector<ll> x(n); cin >> x;
    ll cnt1 = 0, cnt2 = 0;
    set<ll> s3;
    for(ll i = 0; i < n; i++) {
        if(x[i] == -1) cnt1++;
        else if(x[i] == -2) cnt2++;
        else {
            s3.insert(x[i]);
        }
    }
    vector<ll> v(all(s3));
    ll ans = 0;
    for(ll i = 0; i < v.size(); i++) {
        ans = max(ans, min(cnt2 + (ll)v.size() - i - 1, m - v[i]) + min(i + cnt1, v[i] - 1) + 1);
    }
    cout << max(ans, min(max(cnt1 + (ll)v.size(), cnt2 + (ll)v.size()), m)) << "\n";
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