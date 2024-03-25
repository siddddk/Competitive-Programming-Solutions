#include <bits/stdc++.h>
 
using namespace std;
 
#define int int64_t
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int h = 1; h <= tt; h++) {
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        vector<int> v(n + 1, 0);
        set<int> s;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        for (int i = 1; i <= n; i++) {
            s.insert(v[i]);
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            mp[v[x]] += i + 1;
            s.erase(v[x]);
            v[x] = y;
            s.insert(y);
            mp[v[x]] -= (i + 1);
        }
        for (auto i : s) {
            mp[i] += m + 1;
        }
        for(auto x : mp) {
            cout << x.first << " " << x.second << "\n";
        }
        int val = (m + 1) * m * n;
        for (auto i : mp) {
            if (i.second <= 0) continue;
            val -= (i.second * (i.second - 1)) / 2;
        }
        cout << val << "\n";
    }
    return 0;
}