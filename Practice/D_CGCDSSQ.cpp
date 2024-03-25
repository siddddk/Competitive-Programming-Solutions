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

int query(int pos, int tl, int tr, int l, int r) {
    if(tl > r || tr < l) return 0;

    if(tl >= l && tr <= r) return t[pos];
    int m = (tl + tr) >> 1;
    int ans1 = query(2 * pos + 1, tl, m, l, r);
    int ans2 = query(2 * pos + 2, m + 1, tr, l, r);
    return __gcd(ans1, ans2);    
}

void build(vector<int>& a, int pos, int tl, int tr) {
    if(tl == tr) {
        t[pos] = a[tl];
        return;
    }
    int m = (tl + tr) >> 1;
    build(a, 2 * pos + 1, tl, m);
    build(a, 2 * pos + 2, m + 1, tr);
    t[pos] = __gcd(t[2 * pos + 1], t[2 * pos + 2]);
}

void solve(void) 
{
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    
    map<int, int> newdiv, div;
    map<int, long long> res;
    for(int i = 0; i < n; i++) {
        newdiv.clear();
        for(auto x : div) {
            newdiv[__gcd(x.first, a[i])] += x.second;
        } 
        newdiv[a[i]]++;

        for(auto x : newdiv) {
            res[x.first] += x.second;
        }
        swap(div, newdiv);
    }

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << res[x] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}