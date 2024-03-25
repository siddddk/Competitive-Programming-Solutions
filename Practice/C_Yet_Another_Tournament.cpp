#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, m; cin >> n >> m;
    map<ll, ll> map;
    map<ll, ll> winMap;
    vector<ll> a (n, 0), prefix(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        map[a[i]]++;
    }
    if(m == 0) {
        cout << n + 1 - map[0] << "\n";
        return;
    }
    ll wins = 0;
    for(auto x : map) {
        winMap[x.F] = wins;
        wins += x.S;
    }
    for(int i = 0; i < n; i++) {
        // wins.PB({a[i], m[a[i]]});
        cout << a[i] << " " << winMap[a[i]] << "\n";
    }
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