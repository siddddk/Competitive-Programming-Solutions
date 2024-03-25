#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n, m;
    cin >> n >> m;
    if(m < n) {
        cout << "NO" << "\n";
        return;
    }
    if(n == 1) {
        cout << "YES" << "\n";
        cout << m << "\n";
        return;
    }

    if(n&1) {
        cout << "YES" << "\n";
        for(int i = 0; i < n; i++) {
            if(i == n - 1) {
                cout << ((m / n) + (m % n)) << "\n";
            }
            else {
                cout << m / n << " ";
            }
        }
    }
    else {
        if((m % n) % 2 == 0) {
            cout << "YES" << "\n";
            for(int i = 0; i < n; i++) {
                if(i >= n - 2) {
                    cout << ((m / n) + ((m % n) / 2)) << " ";
                }
                else {
                    cout << m / n << " ";
                }
            }
            cout << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
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