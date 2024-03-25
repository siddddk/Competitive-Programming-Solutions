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
    vector<pair<ll, ll>> movies;
    for(ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        movies.PB(make_pair(b, a));
    }
    sort(movies.begin(), movies.end());
    ll prevEnd = movies[0].first;
    ll ans = 1;
    for(ll i = 1; i < n; i++) {
        if(movies[i].second >= prevEnd) {
            ans++;
            prevEnd = movies[i].first;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    solve();
    return 0;
}