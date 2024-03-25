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
    int i, s, c;
};

vector<data> t;

data combine(data l, data r) {
    data res;
    if(l.s > r.s) {
        return l;
    }
    else if(r.s > l.s) {
        return r;
    }
    else {
        if(l.c < r.c) return l;
        else if(r.c < l.c) return r;
        else {
            if(l.i < r.i) return l;
            else return r;
        }
    }
}

data make_data(data a) {
    return a;
}

data query(int v, int tl, int tr, int l, int r) {
    if(tl > r || tr < l) {
        return {-1, -1, -1};
    }
    if (tl >= l && tr <= r) 
        return t[v];

    int m = (tl + tr) / 2;
    data ans1 = query(2 * v + 1, tl, m, l, r);
    data ans2 = query(2 * v + 2, m + 1, tr, l, r);
    return combine(ans1, ans2);
}

void build(vector<data>& a, int v, int tl, int tr) {
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
    vector<data> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].s;
        a[i].i = i;
    }
    for(int i = 0; i < n; i++) cin >> a[i].c;
    t.resize(4 * n);
    build(a, 0, 0, n - 1);
    cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        --l; --r;
        cout << query(0, 0, n - 1, l, r).i + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}