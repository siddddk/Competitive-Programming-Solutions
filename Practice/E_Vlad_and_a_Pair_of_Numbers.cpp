#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(a) begin(a), end(a)
typedef long long ll;
using namespace std;

void solve(void) 
{
    ll n; cin >> n;
    if(n&1) {
        cout << -1 << "\n";
        return;
    }
    bitset<64> b = n;
    string s = b.to_string();
    ll lastSet = __builtin_clzll(n);
    string a (64, '0'), Y (64, '0');
    for(ll i = lastSet; i < 64; i++) {
        if(s[i] == '1') {
            a[i] = '1';
            Y[i] = '0';
        }
        else {
            if(s[i - 1] == '1') {
                a[i] = '1';
                Y[i] = '1';
            }
            else {
                a[i] = '0';
                Y[i] = '0';
            }
        }
    } 
    bitset<64> bA(a), bB(b);
    if(bA.to_ullong() + bB.to_ullong() == 2*n) {
        cout << bA.to_ullong() << " " << bB.to_ullong() << "\n";
    }
    else {
        cout << -1 << "\n";
    }    
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