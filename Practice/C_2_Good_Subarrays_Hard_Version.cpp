#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n; cin >> n;
    ll a[n];
    vector<ll> v;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll q; cin >> q;
    vector<ll> prefix;
    prefix.PB(0);
    ll ans = n;
    for(ll i = 1; i < n; i++) {
        prefix.PB(max(min(a[i] - 1, prefix[i - 1] + 1), 0ll));
    }
    for(ll i = 0; i < prefix.size(); i++) {
        //cout << prefix[i] << " ";
        ans += prefix[i];
    }
    vector<ll> answers;
    while(q--) {
        ll p, x; cin >> p >> x;
        ll temp = prefix[p - 1];
        a[p - 1] = x;
        prefix[p - 1] = max(min(a[p - 1] - 1, prefix[p - 1] + 1), 0ll);
        ans += prefix[p - 1] - temp;
        answers.PB(ans);
    }
    for(ll i = 0; i < q; i++) {
        cout << answers[i] << "\n";
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