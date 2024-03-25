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

int dp[100001];
int k;

int rec(int i) {
    if(i < 0) return 0;

    if(dp[i] != -1) return dp[i];

    int ans = 0;
    ans += rec(i - 1);
    ans += rec(i - k);
    return dp[i] = ans;
} 

void solve(void) 
{
    int q; cin >> k >> q; 
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    rec(100000);    
    for(int i = 1; i <= 100000; i++) {
        dp[i] += dp[i - 1];
    }
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << dp[b] - dp[a - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}