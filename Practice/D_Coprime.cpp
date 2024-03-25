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
    vector<int> a (n);
    vector<int> b (1002, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = i + 1;
    }
    int ans = -1;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            if(__gcd(i, j) == 1) {
                if(b[i] != -1 && b[j] != -1) {
                    ans = max(ans, b[i] + b[j]);
                }
            }
        }
    }

    cout << ans << "\n";
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