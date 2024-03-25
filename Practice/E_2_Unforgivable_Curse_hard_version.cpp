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
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    string sC = s, tC = t;
    sort(all(sC));
    sort(all(tC));
    if(s == t) {
        cout << "YES\n";
        return;
    }
    if((sC != tC) || (k >= n)) {
        cout << "NO\n";
        return;
    }   
    if(n >= 2 * k) {
        cout << "YES\n";
    }
    else {
        if(s.substr(n - k, 2 * k - n) == t.substr(n - k, 2 * k - n)) {
            cout << "YES\n";
        }
        else cout << "NO\n";
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