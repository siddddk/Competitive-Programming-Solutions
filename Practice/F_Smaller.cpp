#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll q; cin >> q;
    ll alen = 1;
    ll blen = 1;
    char bMaxChar = false;
    char aMaxChar = false;
    bool flag = false;
    while(q--) {
        ll d, k; cin >> d >> k;
        string x; cin >> x;
        for(ll i = 0; i < x.length(); i++) {
            if(d == 1) {
                if(x[i] != 'a') aMaxChar = true;
                else alen += k;
            }
            else {
                if(x[i] != 'a') bMaxChar = true;
                else blen += k;
            }
        }
        if(bMaxChar) {
            cout << "YES\n";
        }
        else if(!aMaxChar && alen < blen) {
            cout << "YES\n";
        }
        else cout << "NO\n";        
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