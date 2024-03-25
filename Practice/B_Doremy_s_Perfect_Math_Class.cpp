#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
typedef long long ll;
using namespace std;


void solve(void)
{
    int n; cin >> n;
    vector<int> a (n, 0);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
    }
    int allGCD = __gcd(a[0], a[1]);
    for(int i = 2; i < n; i++) {
        allGCD = __gcd(allGCD, a[i]);
    }
    cout << a[n-1] / allGCD << "\n";
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