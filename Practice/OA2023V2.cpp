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
vector<pair<int, int>> allMasks; 
int k;

int rec(int i, int mask) {
    if(i == allMasks.size()) {
        return (__builtin_popcount(mask) == k);
    }

    if(dp[i].count(mask)) return dp[i][mask];

    int ans = 0;
    ans += rec(i + 1, mask);
    ans += rec(i + 1, mask | allMasks[i].first) * ((1 << allMasks[i].second) - 1);
    return dp[i][mask] = ans;
}

void solve(void) 
{
    int n; cin >> n >> k;
    vector<vector<int>> s(n);
    unordered_map<int, int> masks;
    for(int i = 0; i < n; i++) {
        int mi, currMask = 0; cin >> mi;
        while(mi--) {
            int x; cin >> x;
            currMask |= (1 << x);
        }
        masks[currMask]++;
    }

    for(auto x : masks) {
        allMasks.PB(x);
    }

    cout << rec(0, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}