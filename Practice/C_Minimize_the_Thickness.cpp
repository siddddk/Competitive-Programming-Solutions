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
    ll a[n]; vector<ll> prefix (n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    prefix[0] = a[0];
    for(ll i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    ll ans = n;
    for(ll i = 0; i < n; i++) {
        cout << prefix[i] << " ";
    }
    cout << "\n";
    for(ll i = 0; i < n - 1; i++) {
        if(prefix[n - 1] % prefix[i] == 0) {
            ll num = prefix[n - 1] / prefix[i];
            ll toCheck = prefix[i] * 2;
            ll counter = 0;
            ll prev = i;
            ll maxDistance = i + 1;
            for(ll j = i + 1; j < n; j++) {
                if(prefix[j] == toCheck) {
                    // cout << "j: " << j << " " << "prev: " << prev << "\n";
                    counter++;
                    toCheck += prefix[i];
                    maxDistance = max(maxDistance, j - prev);
                    prev = j;
                }
            }
            // cout << "\n" << "max distance: " << maxDistance << " num : " << num << " counter: " << counter << "\n";
            if(num == counter + 1) {
                ans = min(ans, maxDistance);
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