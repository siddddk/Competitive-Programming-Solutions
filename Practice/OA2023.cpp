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

unordered_map<int, unordered_map<int, int>> dp;

int rec(vector<vector<int>>& s, int n, int k, int i, int mask) {
    if(i == n) {
        return (__builtin_popcount(mask) == k);
    }

    if(dp[i].count(mask)) return dp[i][mask];

    int ans = 0, originalMask = mask;
    ans += rec(s, n, k, i + 1, mask);
    for(auto x : s[i]) {
        mask |= (1 << x);
    }
    ans += rec(s, n, k, i + 1, mask);
    return dp[i][originalMask] = ans;
}

void solve(void) 
{
    int n, k; cin >> n >> k;
    vector<vector<int>> s(n);
    for(int i = 0; i < n; i++) {
        int mi; cin >> mi;
        while(mi--) {
            int x; cin >> x;
            s[i].push_back(x);
        }
    }

    cout << rec(s, n, k, 0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}