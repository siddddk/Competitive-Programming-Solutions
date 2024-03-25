#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
typedef long long ll;
using namespace std;


void solve(void)
{
    int n; cin >> n;
    if(n&1) {
        for(int i = 0; i < n; i++) {
            cout << 3 << " ";
        }
        cout << "\n";
    }
    else {
        for(int i = 0; i < n - 2; i++) {
            cout << 4 << " ";
        }
        cout << 6 << " " << 2 << "\n";
    }
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