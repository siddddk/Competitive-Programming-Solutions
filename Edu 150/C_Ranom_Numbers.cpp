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

ll dp[200001][5][2], n;
vector<ll> cost = {1, 10, 100, 1000, 10000};
string s;

ll rec(ll i, ll c, bool change) {
    ll curr = s[i] - 'A';
    if(i == 0) {
        if(!change) return 10000;
        else {
            if(c > curr) return -cost[curr];
            else return cost[curr];
        }
    }

    if(dp[i][c][change] != -1) return dp[i][c][change];

    
    ll ans = LLONG_MIN;
    for(ll j = 0; j < 5; j++) {
        if(j == curr) {
            if(curr < c) {
                ans = max(ans, -cost[curr] + rec(i - 1, c, change));
            }
            else ans = max(ans, cost[curr] + rec(i - 1, curr, change));
        }   
        else if(!change) {
            if(j < c) {
                ans = max(ans, -cost[j] + rec(i - 1, c, true));
            }
            else ans = max(ans, cost[j] + rec(i - 1, j, true));
        }
    }
    dp[i][c][change] = ans;
    return ans;
}

void solve(void) 
{
    cin >> s;
    n = s.length();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
    cout << rec(n - 1, 0, false);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    while(T--) {
        solve();
        cout << '\n';
    }
    return 0;
}