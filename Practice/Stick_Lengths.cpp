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
    vector<ll> p (n, 0);
    for(ll i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    ll answer = 0;
    for(ll i = 0; i < n; i++) {
        answer += abs(p[i] - p[n/2]);
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