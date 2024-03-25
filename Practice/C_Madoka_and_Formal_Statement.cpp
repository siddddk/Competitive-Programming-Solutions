#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n; cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    bool flag = true;
    for(int i = 0; i < n - 1; i++) {
        if(!(a[i] == b[i])) {
            if(b[i] - b[i + 1] > 1) {
                flag = false;
            }
        }
        if(a[i] > b[i]) flag = false;
    }
    if(a[n - 1] != b[n - 1]) {
        if(b[n - 1] - b[0] > 1) flag = false;
    }
    if(a[n - 1] > b[n - 1]) flag = false;    
    if(flag) cout << "YES";
    else cout << "NO";
    cout << "\n";
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