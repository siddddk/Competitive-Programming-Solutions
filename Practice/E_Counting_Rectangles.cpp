#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> owned (1005, vector<ll> (1005, 0));
    vector<vector<ll>> prefix (1005, vector<ll> (1005, 0));

    for(ll i = 0; i < n; i++) {
        ll h, w;
        cin >> h >> w;
        owned[h][w] += h * w;
    }

    for(ll i = 1; i < 1002; i++) {
        for(ll j = 1; j < 1002; j++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + owned[i][j];
        }
    }

    for(ll i = 0; i < q; i++) {
        ll hs, hb, ws, wb;
        cin >> hs >> ws >> hb >> wb;

        cout << prefix[hb - 1][wb - 1] - prefix[hb - 1][ws] - prefix[hs][wb - 1] + prefix[hs][ws] << "\n";        
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