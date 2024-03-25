#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, c, d; cin >> n >> c >> d;
    vector<ll> a (n, 0);
    bool flag = false;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll sum = 0;
    for(ll i = 0; i < min(d, n); i++) {
        sum += a[i];
    }
    if(sum >= c) {
        cout << "Infinity\n";
        return; 
    }
    if(a[0] * d < c) {
        cout << "Impossible\n";
        return;
    }

    vector<ll> prefix (n, 0);
    prefix[0] = a[0];
    for(ll i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    ll ans = 0;
    for(ll k = 0; k < d; k++) {
        ll q = d / (k + 1);
        ll r = d % (k + 1);
        ll toAdd = 0;
        if(r >= 1) toAdd = prefix[min(r - 1, n - 1)];
        if(prefix[min(k, n - 1)] * q + toAdd >= c) {
            ans = k;
        }
    }
    cout << ans << "\n";
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