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

int f(int n) {
    string s = to_string(n);
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        ans += s[i] - '0';
    }
    n = ans;
    return n;
}

void solve(void) 
{
    int n, q; cin >> n >> q;
    vector<int> a(n, 0); cin >> a;
    set<int> s;
    for(int i = 0; i < n; i++) s.insert(i);
    while(q--) {
        int m; cin >> m;
        if(m == 1) {
            int l, r; cin >> l >> r;
            --l; --r;
            int i = l;
            while(!s.empty()) {
                auto it = s.lower_bound(i);
                if(it == s.end() || *it > r) break;
                a[*it] = f(a[*it]);
                i = *it + 1;
                if(a[*it] < 10) s.erase(it);
            }
        }
        else {
            int x; cin >> x;
            x--;
            cout << a[x] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}