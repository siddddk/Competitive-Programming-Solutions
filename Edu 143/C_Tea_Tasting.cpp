#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
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
    int n; cin >> n;
    vector<ll> a(n), b(n), pref (n, 0); cin >> a >> b;
    pref[0] = b[0];
    for(ll i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + b[i];
    }
    vector<ll> drinks(n + 1, 0), extra(n + 1, 0);

    ll add = 0;
    for(int i = 0; i < n; i++) {
        if(i > 0) add = pref[i - 1];
        int last = upper_bound(pref.begin() + i, pref.end(), a[i] + add) - pref.begin();
        drinks[i]++;
        drinks[last]--;
        extra[last] += a[i] - ((last > 0) ? pref[last - 1] - add : 0);
    } 

    ll cur = 0;
    for(int i = 0; i < n; i++) {
        cur += drinks[i];
        cout << cur * b[i] + extra[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}