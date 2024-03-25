#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

void solve(void)
{
    ll x, s;
    cin >> x >> s;

    if(s % x == 0)
    {
        cout << s/x << "\n";
        return;
    }

    vector<ll> binary;
    ll divisor = 1;
    ll a;

    while(x / divisor != 0)
    {
        a = x & divisor;
        cout << a << "\n";
        binary.PB(x & divisor);
        divisor *= 2;
    }

    reverse(binary.begin(), binary.end());

    for(ll i = 0; i < binary.size(); i++)
    {
        cout << binary[i];
    }
    cout << "\n";

    return;
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