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

vector<vector<pair<int, int>>> dp;
pair<int, int> rec(const vector<int>& a, int i, int sum) {
    if(i == a.size()) return {sum, 0};
    
    if(dp[i][sum + 10000] != make_pair(-1, -1)) return dp[i][sum + 10000];
    
    pair<int, int> ans1 = rec(a, i + 1, sum + a[i]);
    pair<int, int> ans2 = rec(a, i + 1, sum - a[i]);
    ans2.second++;

    pair<int, int> ans;
    
    if(abs(ans1.first) == abs(ans2.first)) {
        if(ans1.second < ans2.second) {
            ans = ans1;
        }
        else {
            if(ans1.first > ans2.first) {
                ans = ans1;
            }
            else ans = ans2;
        }
    }
    else if(abs(ans1.first) < abs(ans2.first)) ans = ans1;
    else ans = ans2;

    return dp[i][sum + 10000] = ans;
}

void solve(void) 
{
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    dp.assign(n, vector<pair<int, int>>(20001, make_pair(-1, -1)));
    cout << rec(a, 0, 0).second << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}