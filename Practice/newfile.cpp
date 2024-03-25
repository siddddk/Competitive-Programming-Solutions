#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;    

ll highestPowerof2(ll n)
{
   ll p = (ll)log2(n);
   return (ll)pow(2, p);
}
 
bool isPowerOfTwo(int x) {
    return x && (!(x & (x - 1)));
}

void solve(void)
{
    ll n, x; cin >> n >> x;
    if(x > n) {
        cout << -1 << "\n";
        return;
    }
    bitset<64> bN = n, bX = x;
    string sN = bN.to_string(), sX = bX.to_string();
    string sAns (64, '0');
    bool flag = true;
    for(int i = 0; i < 64; i++) {
        if(sN[i] == sX[i]) {
            sAns[i] = sN[i];
        }
        else {
            if(sAns[i - 1] == '1') flag = false;
            sAns[i - 1] = '1';
            for(int j = i; j < 64; j++) {
                if(sX[j] != '0') flag = false;
            }
            break;
        }
    }
    bitset<64> ans(sAns);
    if(flag) {
        cout << ans.to_ullong() << "\n";
    } else cout << -1 << "\n";
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