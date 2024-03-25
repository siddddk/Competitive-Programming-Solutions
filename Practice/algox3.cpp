#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int a, b; cin >> a >> b;
    bool flag = false;
    if(a < 2 && b < 2) {
        if((b == 2 && a == 1) || (b == 1 && a == 2)) {
            flag = true;
        }
    }
    else {
        if(a >= b) {
            if(((a + b) % 3 == 0) && 2 * b >= a) flag = true;
        }
        else {
            if(((a + b) % 3 == 0) && 2 * a >= b) flag = true;
        }
    }
    if(a == 0 && b == 0) flag = true;
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}