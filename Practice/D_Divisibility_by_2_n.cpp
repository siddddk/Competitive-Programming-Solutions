#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

int highestPow2(int n) {
    return log2(n & (~(n - 1)));
}

bool isPowerOfTwo(int x) {
    return x && (!(x & (x - 1)));
}

void solve(void)
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int totalPow2 = 0;
    vector<int> powIdx;
    for(int i = 0; i < n; i++) {
        totalPow2 += highestPow2(a[i]);
        if(highestPow2(i + 1) != 0) powIdx.PB(highestPow2(i + 1));
    }
    sort(powIdx.begin(), powIdx.end());
    if(totalPow2 >= n) {
        cout << 0 << "\n";
        return;
    }
    else {
        int num = n - totalPow2;
        int ans = 0;
        for(int i = powIdx.size() - 1; i >= 0; i--) {
            if(powIdx[i] <= num) {
                num -= powIdx[i];
                ans++;
            }
        }
        if(num == 0) {
            cout << ans << "\n";
        }
        else cout << -1 << "\n";
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