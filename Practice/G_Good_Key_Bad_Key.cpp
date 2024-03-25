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
    ll a[n];
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll bal = 0;
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ll sum = bal;
        for(ll j = i; j < min(n, i + 32); j++) {
            ll temp = a[j];
            temp >>= j - i + 1;
            sum += temp;
        }
        ans = max(sum, ans);        
        bal += a[i] - k;
    }
    ans = max(bal, ans);
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




    // ll n, k; cin >> n >> k;
    // ll a[n];
    // for(ll i = 0; i < n; i++) cin >> a[i];
    // ll suffix[n];
    // suffix[n - 1] = a[n - 1];
    // for(ll i = n - 2; i >= 0; i--) {
    //     suffix[i] = suffix[i + 1] + a[i];
    // }
    // ll balance = 0;
    // ll div = 1;
    // for(ll i = 0; i < n; i++) {
    //     // cout << suffix[i] << " ";
    //     if((suffix[i] / (div*2)) > k) {
    //         balance -= k;
    //         balance += (a[i] / div);
    //         // cout << "a ";
    //     }
    //     else {
    //         div *= 2;
    //         balance += (a[i] / div);
    //         // cout << "b ";
    //     } 
    //     cout << "Suff: " << suffix[i] / div << " Div : " << div << " Balance: " << balance << "\n";
    // }
    // // cout << "\n";
    // cout << balance << "\n";