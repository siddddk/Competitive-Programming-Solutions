#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
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
    ll n; cin >> n;
    string s; cin >> s;
    ll minCost = LLONG_MAX;
    for(ll i = 0; i < 26; i++) {
        ll tempCost = 0;
        for(ll j = 0; j < n; j++) {
            tempCost += abs(('a' + i) - s[j]);
        }
        minCost = min(minCost, tempCost);
    }
    cout << minCost << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}