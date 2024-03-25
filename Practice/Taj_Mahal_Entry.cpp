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
    int t[n];
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        if((t[i] % n) <= i) {
            int multiple = t[i] / n;
            ans.PB(make_pair(multiple*n + i, i + 1));
        }
        else {
            int multiple = t[i] / n;
            ans.PB(make_pair(multiple* n + i + n, i + 1));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].second << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}