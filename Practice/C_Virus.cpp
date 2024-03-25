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
    vector<int> a(m, 0);
    for(int i = 0; i < m; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> gap;
    for(int i = 0; i < m - 1; i++) {
        gap.PB(a[i + 1] - a[i] - 1);
    }
    gap.PB(n - a[m - 1] + a[0] - 1);
    sort(gap.begin(), gap.end());
    int p = 0;
    int days = 0;
    for(int i = gap.size() - 1; i >= 0; i--) {
        gap[i] -= days * 2;
        if(gap[i] == 2) days++;
        else days += 2;
        gap[i] -= 1;
        p += max(gap[i], 0);
        if(gap[i] == 0) p++;
    }
    cout << n - p << "\n";
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