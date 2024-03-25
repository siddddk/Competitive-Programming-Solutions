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
    ll n, k; cin >> n >> k;
    vector<ll> a(n); cin >> a;
    sort(all(a));

    ll mx = 0, mn = 0;
    ll counter = 0;
    for(ll i = n - 2; i >= 0; i -= 2) {
        mx += a[i];
        counter++;
        if(counter == k) break;
    }

    counter = 0;
    ll i = 0, j = n - 1;
    for(ll i = 0; i < k; i++) {
        counter++;
        if(counter == k) {
            mn += a[j - 1];
        }
        else {
            mn += a[i];
        }        
        j--;
    }

    cout << mn << ' ' << mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    while(T--) {
        solve();
        cout << '\n';
    }
    return 0;
}