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
    vector<ll> s (n, 0);
    for(ll i = 0; i < n; i++) cin >> s[i];
    vector<ll> sClone = s;
    sort(sClone.begin(), sClone.end());

    for(ll i = 0; i < n; i++) {
        if(s[i] == sClone[n - 1]) {
            cout << s[i] - sClone[n - 2] << " ";
        }
        else {
            cout << s[i] - sClone[n - 1] << " ";
        }
    }
    cout << "\n";
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