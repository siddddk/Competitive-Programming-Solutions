#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
#define N 1000000007
ll exponentiation(ll base,
                        ll exp)
{
    if (exp == 0)
        return 1;
 
    if (exp == 1)
        return base % N;
 
    ll t = exponentiation(base, exp / 2);
    t = (t * t) % N;
 
    // if exponent is even value
    if (exp % 2 == 0)
        return t;
 
    // if exponent is odd value
    else
        return ((base % N) * t) % N;
}

void solve(void)
{
    ll a, n;
    cin >> a >> n;
    if(a >= 0) {
        ll answer = exponentiation(a, n / 2);
        cout << answer % 1000000007 << "\n";
    }
    else {
        cout << 1 << "\n";
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