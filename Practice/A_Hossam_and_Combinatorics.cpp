#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n; cin >> n;
    vector<ll> a(n, 0);
    unordered_map<ll, ll> umap;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        umap[a[i]]++;
    }
    sort(a.begin(), a.end());
    ll front = umap[a[0]];
    ll back = umap[a[n - 1]];
    if(a[0] != a[n - 1]) {
        cout << front*back*2 << "\n";
    }
    else {
        cout << front*(front - 1) << "\n";
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