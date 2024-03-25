#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n; cin >> n;
    if(n&1) {
        cout << 3*n << " " << 4*n << " " << 5*n << " ";
        for(int i = 1; i <= (n - 3) / 2; i++) {
            cout << 4*n - i << " " << 4*n + i << " ";
        }
        cout << "\n";
    }
    else {
        for(int i = 1; i <= n / 2; i++) {
            cout << n - i << " " << n + i << " ";
        }
        cout << "\n";
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