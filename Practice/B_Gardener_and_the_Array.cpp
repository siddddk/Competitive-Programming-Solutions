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
    int n; cin >> n;
    map<int, int> m;
    bool flag = false;
    vector<vector<int>> c;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        vector<int> temp;
        for(int i = 0; i < k; i++) {
            int p; cin >> p;
            m[p]++;
            temp.PB(p);
        }
        c.PB(temp);
    }

    for(int i = 0; i < c.size(); i++) {
        bool tempFlag = true;
        for(int j = 0; j < c[i].size(); j++) {
            if(m[c[i][j]] == 1) tempFlag = false;
        }
        if(tempFlag) {
            flag = true;
            break;
        }
    }
    if(flag) cout << "YES\n";
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