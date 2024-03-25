#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef unsigned long long ll;
using namespace std;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll bs_sqrt(ll x) {
  ll left = 0, right = 2000000123;
  while (right > left) {
      ll mid = (left + right) / 2;
      
      if (mid * mid > x) right = mid;
      else left = mid + 1;
  }
  return left - 1;
}

void solve(void)
{
    ll l, r; cin >> l >> r;
    ll sql = bs_sqrt(l);
    ll sqr = bs_sqrt(r);
    ll ans = 0;
    cout << sql << " " << sqr << "\n";
    if(sql == sqr) {
        for(ll i = 0; i < 3; i++) {
            if(l <= (sql * (sql + i)) && (sql * (sql + i)) <= r) {
                ans++;
                cout << (sql * (sql + i)) << "\n";
            }
        }
    }
    else {
        ans = (sqr - sql - 1) * 3;
        for(ll i = 0; i < 3; i++) {
            if(l <= (sql * (sql + i)) && (sql * (sql + i)) <= r) {
                ans++;
                cout << (sql * (sql + i)) << "\n";
            }
            if (l <= sqr * (sqr + i) && sqr * (sqr + i) <= r) {
                ans++;
                cout << sqr * (sqr + i) << "\n";
            }
        }
    }
    cout << "Ans: " << ans << "\n";
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
    // Original approach
    // ll l, r; cin >> l >> r;
    // ll start = floor(sqrt(l));
    // ll ans = 0;
    // ans += (((start + 1) * (start + 1) - 1) / start) - ((l / start));
    // if(l % start == 0) {
    //     ans++;        
    // }
    // // cout << " start ans: " << ans << "\n";    
    // // cout << "start : " << start << "\n";
    // start += 2;
    // // cout << "start : " << start << " r: " << r << "\n";
    // while(start * start <= r) {
    //     // cout << "start : " << start << " added: " << (((start * start) - 1) / (start - 1))  - (start - 1) + 1 << "\n";
    //     ans += (((start * start) - 1) / (start - 1))  - (start - 1) + 1;
    //     start++;
    // }
    // // cout << " start: " << start << " added : " << (r / (start - 1)) - (start - 1)  + 1 << "\n";
    // ans += (r / (start - 1)) - (start - 1)  + 1;
    // cout << ans << "\n";