#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;

void solve(void) 
{
    ll n, x; cin >> n >> x;
    bitset<64> bN = n, bX = x;
    string sN = bN.to_string(), sX = bX.to_string();
    string ans (64, '0');
    bool flag = true;
    for(ll i = 0; i < 64; i++) {
        if(sN[i] != sX[i]) {
            if(sN[i - 1] != '0') flag = false;
            else {
                ans[i - 1] = '1';
                for(ll j = i; j < 64; j++) {
                    if(sX[j] != '0') flag  = false;
                }
            }
            break;
        }
        else ans[i] = sN[i];
    }
    if(flag) {
        bitset<64> finalAns(ans);
        cout << finalAns.to_ullong() << "\n";
    }
    else cout << -1 << "\n";
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