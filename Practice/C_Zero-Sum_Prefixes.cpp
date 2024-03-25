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
    vector<ll> a (n, 0);
    map<ll, ll> freq;
    ll maxFreq = 0, sum = 0, ans = 0;
    bool flag = true;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            if(flag) ans += freq[0];
            else ans += maxFreq;
            maxFreq = 0; freq.clear();
            flag = false;
        }
        
        sum += a[i];
        maxFreq = max(maxFreq, ++freq[sum]);
    }
    if(flag) ans += freq[0];
    else ans += maxFreq;

    cout << ans << "\n";    
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