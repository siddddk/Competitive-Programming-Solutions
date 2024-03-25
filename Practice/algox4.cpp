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
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> v;
    int minIdx = n + 1;
    int maxIdx = -1;
    int counter = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            minIdx = min(minIdx, i + 1);
            maxIdx = max(maxIdx, i);
            counter++;
        }
    }
    int ans = maxIdx - minIdx;
    ans = max(ans, 1);
    if(counter == 0) {
        ans = 0;
    }
    cout << ans << "\n";
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