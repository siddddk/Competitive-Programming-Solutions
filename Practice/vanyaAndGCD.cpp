#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;

void solve(void)
{
    int n; cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(n + 1, 0);
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i - 1] == 1) {
                dp[i] = 1;
            }
        for(int j = 1; j <= i; j++) {
            if(__gcd(a[i - 1], a[j - 1])) {
                dp[i] += dp[j];
            }
        }
        sum += dp[i];
    }
    cout << sum << "\n";
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