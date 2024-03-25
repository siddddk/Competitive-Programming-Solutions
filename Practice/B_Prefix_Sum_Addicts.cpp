#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, k; cin >> n >> k;
    ll s[k]; 
    for(ll i = 0; i < k; i++) cin >> s[i];
    bool flag = true;
    if(k == 1) {
        cout << "Yes" << "\n";
        return;
    }
    ll prev = LLONG_MIN;
    for(ll i = 0; i < k - 1; i++) {
        if(s[i + 1] - s[i] >= prev) {
            prev = s[i + 1] - s[i];
        }
        else flag = false;
    }
    ll first = s[1] - s[0];
    if(!(s[0] <= first * (n - k + 1))) {
        flag = false;
    }
    if(flag) cout << "Yes" << "\n";
    else cout << "No" << "\n";        
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