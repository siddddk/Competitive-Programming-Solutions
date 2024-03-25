#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n, m; cin >> n >> m;
    int grid[n][m];
    bool cascade = false;
    bool is3 = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if(x == '1') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            int count = grid[i][j] + grid[i + 1][j] + grid[i][j + 1] + grid[i + 1][j + 1];
            if(count <= 2) cascade = true;
            if(count == 3) is3 = true;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += grid[i][j];
        }
    }
    int finalAns = ans;
    if(!cascade && is3) finalAns -= 1;
    else if(!cascade && !is3) finalAns -= 2;

    cout << finalAns << "\n";
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