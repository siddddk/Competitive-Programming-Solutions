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
vector<int> pow2;

int combine(int a, int b, int mid) {
    return (((pow2[mid] * a) % 3) + (b % 3)) % 3;
}

void build(vector<bool>& a, int pos, int tl, int tr) {
    if(tl == tr) {
        t[pos] = a[tl];
        return;
    }   
    int m = (tl + tr) >> 1;
    build(a, 2 * pos + 1, tl, m);
    build(a, 2 * pos + 2, m + 1, tr);
    t[pos] = combine(t[2 * pos + 1], t[2 * pos + 2], tr - m); 
}

void update(int pos, int tl, int tr, int idx, int val) {
    if(tl == tr) {
        t[pos] = val;
        return;
    }
    int m = (tl + tr) >> 1;
    if(idx > m) {
        update(2 * pos + 2, m + 1, tr, idx, val);
    }
    else {
        update(2 * pos + 1, tl, m, idx, val);
    }
    t[pos] = combine(t[2 * pos + 1], t[2 * pos + 2], tr - m);
}

int query(int pos, int tl, int tr, int l, int r) {
    if(tl > r || tr < l) return 0;

    if(tl >= l && tr <= r) {
        return (t[pos] * pow2[r - tr]) % 3;
    }
    
    int m = (tl + tr) >> 1;
    int ans1 = query(2 * pos + 1, tl, m, l, r);
    int ans2 = query(2 * pos + 2, m + 1, tr, l, r);
    return (ans1 + ans2) % 3;
}


void solve(void) 
{
    int n; cin >> n;
    string s; cin >> s;
    vector<bool> a(n);
    for(int i = 0; i < n; i++) a[i] = (s[i] == '1');
    t.resize(4 * n);
    build(a, 0, 0, n - 1);
    int q; cin >> q;
    while(q--) {
        int type, l; cin >> type >> l;
        if(type == 0) {
            int r; cin >> r;
            cout << query(0, 0, n - 1, l, r) << '\n';
        }
        else {
            a[l] = (a[l] || 1);
            update(0, 0, n - 1, l, a[l]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    pow2.resize(100001);
    pow2[0] = 1;
    for(int i = 1; i <= 1e5; i++) {
        pow2[i] = ((pow2[i - 1] % 3) * 2) % 3; 
    }
    solve();
    return 0;
}