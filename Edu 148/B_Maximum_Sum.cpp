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
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        sum += a[i];
    }
    ll counter = 0;
    vector<ll> start(k);
    vector<ll> end(k);
    ll p = 0;
    for(ll i = 0; i < k; i++) {
        start[i] = a[p] + a[p + 1];
        p += 2;
    }  
    p = n - 1;
    for(ll i = 0; i < k; i++) {
        end[i] = a[p];
        p--;
    }
    for(ll i = 1; i < k; i++) {
        start[i] = start[i - 1] + start[i];
        end[i] = end[i - 1] + end[i];
    }
    ll i = k - 2, j = 0;
    ll ans = start[i + 1]; 
    while(j <= k - 1) {
        ll tempAns = end[j];
        if(i >= 0) tempAns += start[i];
        ans = min(ans, tempAns);
        i--;
        j++;
    }
    cout << sum - ans << "\n";
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