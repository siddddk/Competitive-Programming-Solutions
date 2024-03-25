#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n, s; cin >> n >> s;
    vector<int> v;
    vector<int> a(n, 0);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) {
            sum++;
            v.PB(i);
        }
    }
    if(sum < s) {
        cout << -1 << "\n";
        return;
    }
    else if(sum == s) {
        cout << 0 << "\n";
        return;
    }
    v.PB(n);
    int start = sum - s - 1; int end = v.size() - 1;
    int ans = v[start] + 1;
    while(end >= 0) {
        int add = 0;
        if(start >= 0) add = v[start] + 1;
        ans = min(ans, add + (n - v[end]));
        start--;
        end--;
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