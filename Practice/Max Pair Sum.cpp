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
    int left, right;
};

vector<data> t;

data combine(data l, data r) {
    data res;
    res.left = max(l.left, r.right);
    res.right = min(max(l.left, r.right), max(l.right, r.left));
    return res;
}

data make_data(int val) {
    data res;
    res.left = val;
    res.right = 0;
    return res;
}

data query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return make_data(0);
    if (l == tl && r == tr) 
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2 + 1, tl, tm, l, min(r, tm)), 
                   query(v*2 + 2, tm+1, tr, max(l, tm+1), r));
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
    t.resize(4 * n);
    vector<int> a(n); cin >> a;
    cin >> q;

    build(a, 0, 0, n - 1);
    
    while(q--) {
        char c; cin >> c;
        if(c == 'Q') {
            int l, r; cin >> l >> r;
            --l; --r;
            data p = query(0, 0, n - 1, l, r);
            cout << p.left + p.right << '\n';
        }
        else {  
            int i, b; cin >> i >> b;
            --i;
            a[i] = b;
            update(0, 0, n - 1, i, b);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}