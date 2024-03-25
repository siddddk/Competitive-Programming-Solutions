#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    sx--;
    sy--;
    bool upRight = true;
    bool downRight = true;
    bool rightDown = true;
    bool leftDown = true;
    for(int i = 0; i < n; i++) {
        if(abs(i - sx) + abs(0 - sy) <= d) upRight = false;
        if(abs(i - sx) + abs(m - 1 - sy) <= d) downRight = false;
    }

    for(int i = 0; i < m; i++) {
        if(abs(n - 1 - sx) + abs(i - sy) <= d) rightDown = false;
        if(abs(0 - sx) + abs(i - sy) <= d) leftDown = false;
    }

    if((upRight && rightDown) || (leftDown && downRight)) {
        cout << n + m - 2;
    }
    else {
        cout << -1;
    }
    cout << "\n";
    return;
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