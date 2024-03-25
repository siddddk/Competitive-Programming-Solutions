#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, k; cin >> n >> k;
    vector<ll> a(n, 0);
    for(ll i = 0; i < n; i++) cin >> a[i];
    
    set<ll> idx;

    for(ll i = 0; i < n - 1; i++) {
        if(!(a[i] < 2 * a[i + 1])) {
            idx.insert(i);
        }
    }
    ll start = 0;
    ll ans = 0;
    for(ll i = 0; i < n - k; i++) {
        auto it = idx.lower_bound(i);
        if(it != idx.end()) {
            if(*it >= i + k) {
                ans++;
            }
        }
        else ans++;
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