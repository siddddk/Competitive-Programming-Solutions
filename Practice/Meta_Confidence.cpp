#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

struct comp {
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const{
        if(lhs.first == rhs.first) {
            return false;
        }
        else {
            return lhs.first < rhs.first;
        }
    }
};

void solve(void)
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    set<pair<int, int>, comp> s;
    vector<int> ans(n, 0);
    for(int i = n - 1; i >= 0; i--) {
        s.insert(MP(a[i], i));
        auto it = s.upper_bound(MP(a[i], i));
        if(it != s.end()) {
            ans[i] = it->second - i;
        } else {
            ans[i] = n - i;
        }
        cout << i << " " << it->first << " " << ans[i] << "\n";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}