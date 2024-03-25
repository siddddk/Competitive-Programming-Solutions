#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

ll factN(ll N, ll n) {
    ll ans = 0;
    while(N != 0 && N % n == 0) {
        N /= n;
        ans++;
    }
    return ans;
}

void solve(void)
{
    ll n, m; cin >> n >> m;
    ll fact5n = factN(n, 5);
    ll fact2n = factN(n, 2);
    
    ll extra = fact5n > fact2n ? 2 : 5;
    ll diff = abs(fact5n - fact2n);
    ll k = 1;
    while(k * extra <= m && diff--) {
        k *= extra;
    }
    while(k * 10 <= m) k *= 10;
    k *= (m / k);
    cout << k * n << "\n";    
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