#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;

void solve(void) 
{
    int n, k; cin >> n >> k;
    vector<int> l(51, 0), r(51, 0);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if(x == y && x == k) flag = true;
        l[x]++; r[y]++;
    }
    if(l[k] >= 1 && r[k] >= 1) {
        cout << "YES\n";
    }
    else if(flag) {
        cout << "YES\n";
    }
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}