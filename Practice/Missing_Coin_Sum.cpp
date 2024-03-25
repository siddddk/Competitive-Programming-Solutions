#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n; 
    cin >> n;
    vector<ll> x (n, 0); 
    for(ll i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    ll res = 1;
    for(ll i = 0; i < n && x[i] <= res; i++) {
        res += x[i];                
    }
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}