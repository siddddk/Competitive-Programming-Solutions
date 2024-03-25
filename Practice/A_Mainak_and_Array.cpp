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
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int maxChange = a[n - 1] - a[0];
    int maxChange2 = a[n - 1] - a[0];
    for(int i = 0; i < n - 1; i++) {
        maxChange = max(maxChange, (a[i] - a[i + 1]));
    }

    for(int i = 1; i < n - 1; i++) {
        maxChange2 = max(maxChange2, max((a[i] - a[0]), (a[n - 1] - a[i])));
    }
    cout << max(maxChange, maxChange2) << "\n";
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