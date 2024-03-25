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
    vector<ll> a (n, 0);
    vector<pair<ll, ll>> v (n, {0, 0});
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll prevOnes = 0;
    for(ll i = 0; i < n; i++) {
        v[i].F = prevOnes;
        if(a[i] == 1) prevOnes++;
    }
    ll nextZeroes = 0;
    for(ll i = n - 1; i >= 0; i--) {
        v[i].S = nextZeroes;
        if(a[i] == 0) nextZeroes++;
    }
    ll inversions = 0;
    ll maxAdded = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i] == 0) {
            maxAdded = max(maxAdded, v[i].S - v[i].F);
        }
        else {
            maxAdded = max(maxAdded, v[i].F - v[i].S);
            inversions += v[i].S;
        }
    }
    cout << inversions + maxAdded << "\n";
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