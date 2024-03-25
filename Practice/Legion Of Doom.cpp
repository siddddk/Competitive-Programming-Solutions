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

vector<ll> t;
vector<ll> lazy;

ll query(ll pos, ll tl, ll tr, ll l, ll r) {

    if(lazy[pos] != 0) {
        t[pos] += lazy[pos] * (tr - tl + 1);
        if(tl != tr) {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if(tl > r || tr < l) return 0;

    if(tl >= l && tr <= r) {
        return t[pos];
    }

    ll m = (tl + tr) >> 1;
    ll ans1 = query(2 * pos + 1, tl, m, l, r);
    ll ans2 = query(2 * pos + 2, m + 1, tr, l, r);
    return ans1 + ans2;
}

void update(ll pos, ll tl, ll tr, ll l, ll r, ll inc) {
    if(l > r) return;

    if(lazy[pos] != 0) {
        t[pos] += lazy[pos] * (tr - tl + 1);
        if(tl != tr) {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if(l > tr || r < tl) return;

    if(tl >= l && tr <= r) {
        t[pos] += inc * (tr - tl + 1);
        if(tl != tr) {
            lazy[2 * pos + 1] += inc;
            lazy[2 * pos + 2] += inc;
        }
        return;
    }
    ll m = (tl + tr) >> 1;
    update(2 * pos + 1, tl, m, l, r, inc);
    update(2 * pos + 2, m + 1, tr, l, r, inc);
    t[pos] = t[2 * pos + 1] + t[2 * pos + 2];
}

void solve(void) 
{
    ll n; cin >> n;
    vector<ll> a(n, 0);
    t.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
    ll q; cin >> q;
    while(q--) {
        ll type, l, r; cin >> type >> l >> r;
        --l; --r;
        if(type == 0) {
            ll v; cin >> v;
            update(0, 0, n - 1, l, r, v);
        }
        else {
            cout << query(0, 0, n - 1, l, r) << '\n';
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