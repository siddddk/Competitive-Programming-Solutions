#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;

struct data {
    ll ss, sum;
};

struct lazydata {
    ll inc, val;
};

vector<data> t(400001);
vector<lazydata> lazy(400001);

data combine(data l, data r) {
    data res;
    res.ss = l.ss + r.ss;
    res.sum = l.sum + r.sum;
    return res;
}

data make_data(ll val) {
    data res;
    res.ss = val * val;
    res.sum = val;
    return res;
}

void rangeAdd(ll tl, ll tr, ll inc, ll pos) {
    t[pos].ss += (tr - tl + 1) * (inc) * (inc) + 2 * t[pos].sum * inc;
    t[pos].sum += (tr - tl + 1) * (inc);
}

void rangeSet(ll tl, ll tr, ll val, ll pos) {
    t[pos].ss = (tr - tl + 1) * val * val;
    t[pos].sum = (tr - tl + 1) * val;
}

void build(vector<ll>& a, ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = make_data(a[tl]);
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2 + 1, tl, tm);
        build(a, v*2 + 2, tm+1, tr);
        t[v] = combine(t[v*2 + 1], t[v*2 + 2]);
    }
}

data query(ll v, ll tl, ll tr, ll l, ll r) {
    if(tl > r || tr < l) return make_data(0);

    if(tl >= l && tr <= r) {
        return t[v];
    }    
    ll m = (tl + tr) >> 1;
    data ans1 = query(2 * v + 1, tl, m, l, r);
    data ans2 = query(2 * v + 2, m + 1, tr, l, r);
    return combine(ans1, ans2);
}

void updateLazyInc(ll tl, ll tr, ll l, ll r, ll pos, ll inc) {
    if(tl > tr) return;

    ll m = (tl + tr) >> 1;

    if(lazy[pos].inc != 0) {
        rangeAdd(tl, tr, lazy[pos].inc, pos);

        if(tl != tr) {
            lazy[2 * pos + 1].inc += lazy[pos].inc;
            lazy[2 * pos + 2].inc += lazy[pos].inc;
        }
        lazy[pos].inc = 0;
    }

    if(lazy[pos].val != 0) {
        rangeSet(tl, tr, lazy[pos].val, pos);
        if(tl != tr) {
            lazy[2 * pos + 1].val = lazy[pos].val;
            lazy[2 * pos + 2].val = lazy[pos].val;
        }
        lazy[pos].val = 0;
    }

    if(l > tr || r < tl) return;

    if(tl >= l && tr <= r) {
        rangeAdd(tl, tr, inc, pos);
        if(tl != tr) {
            lazy[2 * pos + 1].inc += inc;
            lazy[2 * pos + 2].inc += inc;
        }
        return;
    }

    updateLazyInc(tl, m, l, r, 2 * pos + 1, inc);
    updateLazyInc(m + 1, tr, l, r, 2 * pos + 2, inc);
    t[pos] = combine(t[2 * pos + 1], t[2 * pos + 2]);
}

void updateLazySet(ll tl, ll tr, ll l, ll r, ll pos, ll val) {
    if(tl > tr) return;

    ll m = (tl + tr) >> 1;
    
    if(lazy[pos].val != 0) {
        rangeSet(tl, tr, val, pos);
        if(tl != tr) {
            lazy[2 * pos + 1].val = lazy[pos].val;
            lazy[2 * pos + 2].val = lazy[pos].val;
        }
        lazy[pos].val = 0;
    }

    if(l > tr || r < tl) return;

    if(tl >= l && tr <= r) {
        rangeSet(tl, tr, val, pos);
        if(tl != tr) {
            lazy[2 * pos + 1].val = val;
            lazy[2 * pos + 2].val = val;
        }
        return;
    }
    
    updateLazySet(tl, m, l, r, 2 * pos + 1, val);
    updateLazySet(m + 1, tr, l, r, 2 * pos + 2, val);
    t[pos] = combine(t[2 * pos + 1], t[2 * pos + 2]);
}

void solve(void) 
{
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(auto& x : lazy) {
        x.inc = 0;
        x.val = 0;
    }
    for(auto& x : t) {
        x.ss = 0;
        x.sum = 0;
    }
    build(a, 0, 0, n - 1);
    while(q--) {
        ll type, l, r; cin >> type >> l >> r; 
        --l; --r;
        if(type == 2) {
            cout << query(0, 0, n - 1, l, r).ss << '\n';
        } 
        else if(type == 1) {
            ll inc; cin >> inc;
            updateLazyInc(0, n - 1, l, r, 0, inc);
        }
        else {
            ll x; cin >> x;
            updateLazySet(0, n - 1, l, r, 0, x);
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