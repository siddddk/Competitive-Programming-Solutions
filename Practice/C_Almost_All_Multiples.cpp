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
    int n, x; cin >> n >> x;
    if(n % x == 0) {
        if(x == n) {
            cout << n << " ";
            for(int i = 2; i < n; i++) {
                cout << i << " ";
            }
            cout << 1 << "\n";
            return;
        }
        else {
            vector<int> p (n + 1, 0);
            p[1] = x; p[n] = 1; p[x] = n;
            for(int i = 2; i < n; i++) {
                if(i != x) p[i] = i;
            
            }
            int idx = x;

            for(int i = x + 1; i < n; i++) {
                if(p[i] % idx == 0 && p[idx] % i == 0) {
                    swap(p[idx], p[i]);
                    idx = i;
                }
            }

            for(int i = 1; i <= n; i++) {
                cout << p[i] << " ";
            }
            cout << "\n";
            // for(int i = 1; i <= n; i++) {
            //     cout << i << " ";
            // }
            // cout << "\n";
        }
    }
    else {
        cout << -1 << "\n";
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