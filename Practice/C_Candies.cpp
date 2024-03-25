#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

bool check(ll k, ll n) {
    ll cur = n;
    ll sum = 0;
    while(cur > 0) {
        ll toSubtract = min(cur, k);
        sum += toSubtract;
        cur -= toSubtract;
        cur -= (cur / 10);
    }
    return ((2 * sum) >= n);
}

void solve(void)
{
    ll n;
    cin >> n;
    ll x = -1;
    for(ll b = (n / 2); b >= 1; b /= 2) {
        while(!check(x + b, n)) x += b;
    }
    cout << x + 1 << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}