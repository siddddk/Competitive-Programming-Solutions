#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

ll isSquare(long double x) {
    long long a = sqrt(x);
    if(a * a == x) {
        return a;
    } else return 0;
}

ll findSq(ll n) {
    ll i = 0;
    while(!isSquare(i + n)) {
        i++;
    }
    return isSquare(i + n);
}

void solve(void)
{
    ll n; cin >> n;
    ll i = 0;
    ll a = findSq(n - 1);
    ll lim = n - 1;
    vector<ll> ans;
    for(ll j = n - 1; j >= 0; j--) {
        if((a * a) - j <= lim) {
            ans.PB(a * a - j);
        }
        else {
            a--;
            lim = j;
            j++;
        }
    }
    for(ll j = ans.size() - 1; j >= 0; j--) {
        cout << ans[j] << " ";
    }
    cout << "\n";
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