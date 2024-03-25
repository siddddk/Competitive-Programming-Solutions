#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void solve(void) 
{
    ll n; cin >> n;
    vector<ll> a(n); cin >> a;
    vector<ll> aClone = a;
    bool flag = true;
    reverse(all(aClone));
    for(int i = 0; i < n; i++) {
        if(a[i] != aClone[i]) flag = false;
    }
    if(flag) {
        cout << 0 << "\n";
        return;
    }
    ll i = (n - 1) / 2, j = (n + 1) / 2;
    if(n&1) {
        i = (n / 2) - 1;
        j = (n / 2) + 1;
    }
    ll ans = abs(a[i] - a[j]);
    i--; j++;
    for( ;i >= 0; i--) {        
        ans = __gcd(ans, abs(a[i] - a[j]));
        j++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}