#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

ll ok(vector<ll> & cnt, ll t, ll m, ll n) {
    ll tasks = 0;
    for(ll i = 0; i < n; i++) {
        tasks += min(t, cnt[i]);
        tasks += (t - min(t, cnt[i])) / 2;
    }
    if(tasks >= m) return true;
    else return false;
}

void solve(void)
{
    ll n, m; cin >> n >> m;
    vector<ll> a (m, 0);
    unordered_map<ll, ll> umap;
    for(ll i = 0; i < m; i++) {
        cin >> a[i];
        umap[a[i]]++;
    }
    vector<ll> cnt (n, 0);
    for(auto x : umap) {
        cnt[x.F - 1] = x.S;
    }

    ll x = -1;
    for (ll b = 2*m + 1; b >= 1; b /= 2) {
        while (!ok(cnt, x+b, m, n)) x += b;
    }
    cout << x + 1ll << "\n";
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