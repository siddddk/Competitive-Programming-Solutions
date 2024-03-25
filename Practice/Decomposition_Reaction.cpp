#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll Q[n];
    ll C[m];
    ll X[m];

    for(ll i = 0; i < n; i++) cin >> Q[i];

    for(ll i = 0; i < m; i++)
    {
        cin >> C[i] >> X[i];
        
        for(ll j = 0; j < X[i]; j++)
        {
            ll w, c;
            cin >> w >> c;
            Q[c-1] += (Q[C[i]-1]*w)%1000000007;
        }
        Q[C[i]-1] = 0;
    }

    for(ll i = 0; i < n; i++)
    {
        cout << Q[i] << "\n";
    }
    return 0;
}