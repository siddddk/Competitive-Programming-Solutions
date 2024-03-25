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

vector<int> t;

int combine(int l, int r) {
    return max(l, r);
}

int make_data(int val) {
    return val;
}

int query(int v, int tl, int tr, int l, int r) {
    if (tl > r || tr < l)  
        return make_data(0);
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
        cout << query(0, 0, n - 1, l, r) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}