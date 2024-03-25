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

vector<pair<ll, ll>> t;

pair<ll, ll> combine(pair<ll, ll> l, pair<ll, ll> r) {
    return max(l, r);
}

pair<ll, ll> make_data(pair<ll, ll> val) {
    return val;
}

pair<ll, ll> query(ll v, ll tl, ll tr, ll l, ll r) {
    if(tl > r || tr < l) return {-1, -1};
    if (tl >= l && tr <= r) 
        return t[v];
    ll m = (tl + tr) >> 1;
    pair<ll, ll> ans1 = query(2 * v + 1, tl, m, l, r);
    pair<ll, ll> ans2 = query(2 * v + 2, m + 1, tr, l, r);
    return max(ans1, ans2);
}

void build(vector<ll>& a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = make_data({a[tl], tl});
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2 + 1, tl, tm);
        build(a, v*2 + 2, tm+1, tr);
        t[v] = combine(t[v*2 + 1], t[v*2 + 2]);
    }
}

void solve(void) 
{
    ll n, q; cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n - 1; i++) {
        cin >> a[i];
        --a[i];
    }
    a.push_back(n);
    t.resize(4 * n);
    build(a, 0, 0, n - 1);
    cout << '\n';
    vector<ll> dp(n);
    dp[n - 1] = 0;
    ll ans = 0;
    for(ll i = n - 2; i >= 0; i--) {
        ll mx = query(0, 0, n - 1, i + 1, a[i]).second;
        dp[i] = a[i] - mx + dp[mx] + 1;
        ans += dp[i];
    }
    cout << ans << '\n';    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}