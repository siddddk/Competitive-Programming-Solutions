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
    ll x[n];
    for(ll i = 0; i < n; i++) cin >> x[i];
    ll answer = n;
    unordered_map<ll, bool> umap;
    for(ll i = 0; i < n; i++) {
        if(umap.count(x[i] - 1)) {
            answer--;
        }
        umap[x[i]] = true;
    }
    cout << answer << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}