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
    vector<int> a(n, 0), b(n, 0);
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i] < a[j] || (a[i] == a[j] && b[i] < b[j])) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
                ans.PB({i, j});
            }
        }
    }
    
    if(is_sorted(b.begin(), b.end())) {
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i].F + 1 << " " << ans[i].S + 1 << "\n";
        }
    }
    else cout << -1 << "\n";
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