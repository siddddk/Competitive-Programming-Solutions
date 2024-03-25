#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n; cin >> n;
    if(n == 1 || n == 3) {
        cout << -1 << "\n";
        return;
    }
    vector<ll> ans;
    for(ll i = 0; i < n; i++) {
        ans.PB(n - i);
    }
    if(n == 5) {
        cout << "5 4 1 2 3" << "\n";
        return;
    }

    if(n&1) {
        swap(ans[n / 2], ans[n / 2 - 1]);
    }
    bool flag = true;
    for(ll i = 0; i < n; i++) {
        if(ans[i] == i + 1) flag = false;
        cout << ans[i] << " ";
    }
    cout << "\n";
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