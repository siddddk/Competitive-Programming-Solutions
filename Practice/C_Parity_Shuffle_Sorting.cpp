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
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> op;
    if(n == 1) {
        cout << 0 << "\n";
        return;
    }
    op.PB({1, n});
    int sum = a[0] + a[n - 1];
    if(sum&1) {
        a[n - 1] = a[0];
    }
    else {
        a[0] = a[n - 1];
    }

    for(int i = 1; i < n - 1; i++) {
        int s = a[0] + a[i];
        if(s&1) {
            op.PB({1, i + 1});
        }
        else {
            op.PB({i + 1, n});
        }
    }



    cout << op.size() << "\n";
    for(int i = 0; i < op.size(); i++) {
        cout << op[i].F << " " << op[i].S << "\n";
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