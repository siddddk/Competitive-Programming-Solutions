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
    string s; cin >> s;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    vector<bool> vis (n, false);
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '0' && s[i + 1] == '1') {
            // cout << i << " ";
            vis[i] = true;
            int minA = a[i];
            ans += a[i];
            int start = i + 1;
            while(start < n && s[start] == '1') {
                // cout << start << " ";
                vis[start] = true;
                minA = min(minA, a[start]);
                ans += a[start];
                start++;
            }
            i = start - 1;
            ans -= minA;
            // cout << "\n";
        }
    }

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            if(s[i] == '1') ans += a[i];
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