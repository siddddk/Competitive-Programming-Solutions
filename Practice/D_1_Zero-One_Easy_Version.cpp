#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, x, y; cin >> n >> x >> y;
    string a, b; cin >> a >> b;
    ll diff = 0;
    ll diff1 = 0;
    ll diff0 = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            diff++;
            if(a[i] == '0') diff0++;
            else diff1++;
        }
    }
    if(diff&1) {
        cout << -1 << "\n";
        return;
    }
    ll cost = (diff / 2) * y;
    if(diff == 2) {
        ll caseCost;
        for(ll i = 0; i < n; i++) {
            if(a[i] != b[i]) {
                if(i < n - 1 && a[i + 1] != b[i + 1]) {
                    caseCost = min(x, 2 * y);
                    cout << caseCost << "\n";
                    return;
                }
            }
        }
        caseCost = y;
        cout << caseCost << "\n";
        return;
    }

    cout << cost << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}