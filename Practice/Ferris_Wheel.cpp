#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, x;
    cin >> n >> x;
    ll p[n];
    for(ll i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    ll start = 0, end = n - 1, ans = 0;
    while(start < end) {
        if(p[start] + p[end] <= x) {
            ans++;
            start++;
            end--;
        }
        else {
            ans++;
            end--;
        }
    }
    if(start == end) ans++;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    solve();
    return 0;
}