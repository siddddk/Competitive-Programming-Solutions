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

int n;
vector<int> dp;

int rec(vector<int>& a, int i) {
    if(i == n - 1) return 0;

    if(dp[i] != -1) return dp[i];

    int ans1 = INT_MAX, ans2 = INT_MAX;
    if(i + 1 < n) {
        ans1 = rec(a, i + 1) + abs(a[i] - a[i + 1]);
    }

    if(i + 3 < n) {
        ans2 = rec(a, i + 3) + abs(a[i] - a[i + 3]);
    }

    return dp[i] = min(ans1, ans2);
}

void solve(void) 
{
    cin >> n;
    vector<int> a(n); cin >> a;
    dp.assign(n, -1);
    cout << rec(a, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while(T--) {
        solve();
        cout << '\n';
    }
    return 0;
}