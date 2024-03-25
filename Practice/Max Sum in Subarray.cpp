#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
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

struct data {
    int sum, pref, suff, ans;
};

vector<data> t;

data combine(data l, data r) {
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

data make_data(int val) {
    data res;
    res.sum = val;
    res.pref = res.suff = val;
    res.ans = val;
    return res;
}

data query(int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l)  
        return make_data(-1e4);
    if (tl >= l && tr <= r) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2 + 1, tl, tm, l, min(r, tm)), query(v*2 + 2, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_data(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2 + 1, tl, tm, pos, new_val);
        else
            update(v*2 + 2, tm + 1, tr, pos, new_val);
        t[v] = combine(t[v*2 + 1], t[v*2 + 2]);
    }
}

void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_data(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2 + 1, tl, tm);
        build(a, v*2 + 2, tm+1, tr);
        t[v] = combine(t[v*2 + 1], t[v*2 + 2]);
    }
}

void solve(void) 
{
    int n, q; cin >> n;
    vector<int> a(n); cin >> a;
    t.resize(4 * n);
    build(a, 0, 0, n - 1);
    cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        --l; --r;
        cout << query(0, 0, n - 1, l, r).ans << '\n';
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}