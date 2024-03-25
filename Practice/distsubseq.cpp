#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define aint(x) begin(x), end(x)
using namespace std;

int dp[1001][1001];

int rec(char* a, char* b, int n, int m) {
    if(n == 0 && m != 0) return 0;
    else if(m == 0 && n != 0) return 1;
    else if(m == 0 && n == 0) return 1;

    // cout << "Caint for " << a[0] << " " << b[0] << "\n";
    if(dp[n][m] == -1) {
        int ans;
        if(a[0] == b[0]) {
            ans = rec(a + 1, b, n - 1, m) + rec(a + 1, b + 1, n - 1, m - 1);
        }
        else {
            ans = rec(a + 1, b, n - 1, m);
        }
        dp[n][m] = ans;
        return ans;
    }
    else return dp[n][m];
}

void solve(void)
{
    string A, B; cin >> A >> B;
    int n = A.length(); int m = B.length();
    char* a = new char[n]; 
    char* b = new char[m];
    for(int i = 0; i < n; i++) a[i] = A[i];
    for(int i = 0; i < m; i++) b[i] = B[i];
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) dp[i][j] = -1;
    }
    cout << rec(a, b, n, m) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}