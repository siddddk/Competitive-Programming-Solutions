#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n, q; cin >> n >> q;
    vector<int> a (n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> wins (n, {-1, -1});
    int max = a[0];
    wins[0].F = 1;
    if(a[0] != n) {
        int max = a[0], curr = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] > max) {
                wins[curr].S = i;
                wins[i].F = i;
                curr = i;
                max = a[i];
            }
            if(a[i] == n) {
                wins[i].F = i;
                wins[i].S = 1e9 + 3;
                break;
            }
        }
    } 
    else wins[0].S = 1e9 + 3;
    while(q--) {
        int i, k; cin >> i >> k;
        --i;
        cout << min(wins[i].S - wins[i].F, k < wins[i].F ? 0 : k - wins[i].F + 1) << "\n";
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