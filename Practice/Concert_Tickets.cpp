#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, m;
    cin >> n >> m;
    ll t[m];
    multiset<ll> tickets;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        tickets.insert(x);
    }
    for(ll i = 0; i < m; i++) cin >> t[i];
    
    for(ll i = 0; i < m; i++) {
        auto it = tickets.upper_bound(t[i]);
        if(it == tickets.begin()) {
            cout << -1 << "\n";
        }
        else {
            cout << *(--it) << "\n";
            tickets.erase(it);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}