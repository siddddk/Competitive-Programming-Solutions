#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

pair<ll, ll> rec(ll * a, ll n) {
    // cout << "Call for size: " << n << "\n";
    // for(ll i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    if(n == 0) return {0, 0};
    if(n == 2) {
        if(abs(a[0] - a[1]) == 1) {
            if(a[0] > a[1]) return {1, a[0]};
            else return {0, a[1]};
        }
        else return {-1, -1};
    }
    pair<ll, ll> p1 = rec(a, n / 2);
    pair<ll, ll> p2 = rec(a + n / 2, n / 2);
    if(p1.F != -1 || p2.F != -1) {
        if(abs(p2.S - p1.S) == n / 2) { 
            ll add = 0;
            if(p1.S > p2.S) add = 1;
            // cout << "\n returned: " << p1.F + p2.F + add << " " << max(p1.S, p2.S) << "\n";
            return {p1.F + p2.F + add, max(p1.S, p2.S)};
        }
        else return {-1, -1};
    }
    else {
        return {-1, -1};
    }
}

void solve(void)
{
    ll m; cin >> m;
    ll * a = new ll[m];
    for(ll i = 0; i < m; i++) {
        cin >> a[i];       
    }
    cout << rec(a, m).F << "\n";
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