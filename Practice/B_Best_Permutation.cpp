#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n;
    cin >> n;
    if(n <= 6) {
        if(n == 1) {
            cout << 1 << "\n";
        }
        else if(n == 2) {
            cout << 1 << " " << 2 << "\n";
        }
        else if(n == 3) {
            cout << 1 << " " << 2 << " " << 3 << "\n";
        }
        else if(n == 4) {
            cout << 2 << " " << 1 << " " << 3 << " " << 4 << "\n";
        }
        else if(n == 5) {
            for(int i = 0; i < 5; i++) {
                cout << i + 1 << " ";
            }
            cout << "\n";
        }
        else if(n == 6) {
            cout << 4 << " " << 5 << " " << 1 << " " << 2 << " " << 3 << " " << 6 << "\n";
        }
    }
    else if(n&1) {
        for(int i = n; i >= 1; i--) {
            if(i != 1 && i != 2 && i != n -3 && i != n) {
                cout << i << " ";
            }
        }
        cout << 1 << " " << 2 << " " << n - 3 << " " << n << "\n";
    }
    else {
        cout << 3 << " ";
        for(int i = n; i >= 1; i--) {
            if(i != 1 && i != 2 && i != n -3 && i != n && i != n - 1 && i != 3) {
                cout << i << " ";
            }
        }
        cout << n - 1 << " ";
        cout << 1 << " " << 2 << " " << n - 3 << " " << n << "\n";
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