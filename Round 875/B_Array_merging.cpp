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

void solve(void) 
{
    int n; cin >> n;
    vector<int> a(n), b(n); cin >> a >> b;
    unordered_map<int, int> umapa, umapb;
    int curra = 1, currb = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1]) {
            curra++;
        }
        else {
            umapa[a[i - 1]] = max(umapa[a[i - 1]], curra);
            curra = 1;
        }

        if(b[i] == b[i - 1]) {
            currb++;
        }
        else {
            umapb[b[i - 1]] = max(umapb[b[i - 1]], currb);
            currb = 1;
        }
    }
    umapa[a[n - 1]] = max(umapa[a[n - 1]], curra);
    umapb[b[n - 1]] = max(umapb[b[n - 1]], currb);
    
    int ans = 0;
    for(auto x : umapa) {
        // cout << x.first << ' ' << x.second << '\n';
        ans = max(umapa[x.first] + umapb[x.first], ans);
    }
    // cout << '\n';
    for(auto x : umapb) {
        // cout << x.first << ' ' << x.second << '\n';
        ans = max(umapb[x.first] + umapa[x.first], ans);
    }
    cout << ans << '\n';
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