#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n; cin >> n;
    int b[n + 1];
    for(int i = 0; i < n; i++) {
        cin >> b[i + 1];
    }
    vector<bool> dp (n + 1, false);
    dp[0] = true;
    for(int i = 1; i <= n; i++) {
        if(dp[i - 1]) {
            if(i + b[i] <= n) dp[i + b[i]] = true;
        }
        if(i - b[i] - 1 >= 0) {
            if(dp[i - b[i] - 1]) dp[i] = true;
        }
    }

    if(dp[n]) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    
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