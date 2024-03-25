#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
using namespace std;

int n, m;
int dp[101][101][101];
string a, b;
int rec(int i, int j, int k) {
    if(k == 0) return 0;
    if(k > n || k > m) return -1;
    if(i == n || j == m) return -1;
    
    if(dp[i][j][k] == -1) {
        int ans;
        if(a[i] == b[j]) {
            int ans1 = -1, ans2 = -1;
            int intA = rec(i + 1, j + 1, k - 1), intB = rec(i + 1, j + 1, k);
            if(intA != -1) {
                ans1 = intA + a[i];
            }
            ans = max(ans1, intB);
        }
        else {
            ans = max(rec(i + 1, j, k), rec(i, j + 1, k));
        }
        dp[i][j][k] = ans;
        return ans;
    } else return dp[i][j][k];
}


void solve()
{
    string b1, b2; cin >> b1 >> b2;
    int k; cin >> k;
    a = b1, b = b2;
    n = b1.length(); m = b2.length();
    memset(dp, -1, sizeof(dp));
    int ans = rec(0, 0, k);
    if(ans == -1) {
        cout << 0 << "\n";
    }
    else cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}