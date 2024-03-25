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

ll a[5002], cold[5002], hot[5002], dp[5002][5002], n;

ll rec(ll i, ll j) {
    ll mx = max(i, j);
    if(mx + 1 > n) return 0;
    
    if(dp[i][j] == -1) {
        ll add1 = (a[mx + 1] == a[i]) ? hot[a[mx + 1]] : cold[a[mx + 1]];
        ll add2 = (a[mx + 1] == a[j]) ? hot[a[mx + 1]] : cold[a[mx + 1]];
        ll ans1 = rec(mx + 1, j) + add1;
        ll ans2 = rec(i, mx + 1) + add2;
        dp[i][j] = min(ans1, ans2);
        return dp[i][j];        
    } else return dp[i][j];
}

void solve(void) 
{
    ll k; cin >> n >> k;
    a[0] = -1;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= k; i++) cin >> cold[i];
    for(ll i = 1; i <= k; i++) cin >> hot[i];
    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < n + 1; j++) dp[i][j] = -1;
    }
    cout << rec(0, 0) << "\n";
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