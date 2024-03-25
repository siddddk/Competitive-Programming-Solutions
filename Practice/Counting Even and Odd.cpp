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
    int even, odd;
};

data make_data(int val) {
    data res;
    res.odd = 0;
    res.even = 0;
    if(val&1) res.odd++;
    else res.even++; 
    return res;
}

data combine(data a, data b) {
    data res;
    res.odd = a.odd + b.odd;
    res.even = a.even + b.even;
    return res;
}

vector<data> t;

void build(vector<int>& a, int pos, int tl, int tr) {
    if(tl == tr) {
        t[pos] = make_data(a[tl]);
        return;
    }

    int m = (tl + tr) >> 1;
    build(a, 2 * pos + 1, tl, m);
    build(a, 2 * pos + 2, m + 1, tr);    

    t[pos] = combine(t[2 * pos + 1], t[2 * pos + 2]);
}

void update(int pos, int tl, int tr, int idx, int val) {
    if(tl == tr) {
        t[pos] = make_data(val);
        return;
    }
    
    int m = (tl + tr) >> 1;
    if(idx > m) {
        update(2 * pos + 2, m + 1, tr, idx, val);
    }
    else {
        update(2 * pos + 1, tl, m, idx, val);
    }
    t[pos] = combine(t[2 * pos + 1], t[2 * pos + 2]);
}

data query(int pos, int tl, int tr, int l, int r) {
    if(tl > tr) return {0, 0};

    if(tl > r || tr < l) return {0, 0};

    if(tl >= l && tr <= r) return t[pos];

    int m = (tl + tr) >> 1;
    data ans1 = query(2 * pos + 1, tl, m, l, r);
    data ans2 = query(2 * pos + 2, m + 1, tr, l, r);
    return combine(ans1, ans2);
}


void solve(void) 
{
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    int q; cin >> q;
    t.resize(4 * n);
    build(a, 0, 0, n - 1);
    while(q--) {
        int type, a, b; cin >> type >> a >> b;
        if(type == 0) {
            --a; 
            update(0, 0, n - 1, a, b);
        }
        else {
            --a; --b;
            if(type == 1) {
                cout << query(0, 0, n - 1, a, b).even;
            }
            else {
                cout << query(0, 0, n - 1, a, b).odd;
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}