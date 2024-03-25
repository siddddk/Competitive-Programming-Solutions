#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;



void solve(void)
{
    ll n, q; cin >> n >> q;
    ll a[n];
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll Q = 0;
    string s = "";
    for(ll i = n - 1; i >= 0; i--) {
        if(a[i] <= Q) s += "1";
        if(a[i] > Q && Q < q) {
            s += "1";
            Q++;
        }
        else if(a[i] > Q && Q == q) {
            s += "0";
        }
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";



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