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
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    int mn = *min_element(all(a)), val = accumulate(a.begin(), a.end(), 0);
    cout << val - 2*mn << "\n"; 
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