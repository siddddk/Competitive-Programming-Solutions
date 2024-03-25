#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
 
 
void solve(void)
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n];
    vector<ll> b(m, 0);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) {
        cin >> b[i];
    }
 
    sort(a, a + n);
    sort(b.begin(), b.end());
    ll ans = 0;
    ll i = 0;
    ll j = 0;
    while(i < n && j < m) {
        if(abs(a[i] - b[j]) <= k) {
            i++;
            j++;
            ans++;
        }
        else {
            if(a[i] - b[j] > k) {
                j++;
            }
            else {
                i++;
            }
        }
    }
    cout << ans << "\n";
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}