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
    int a[n];
    vector<int> b;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(n == 1) {
        cout << "YES" << "\n";
        return;
    }

    for(int i = 0; i < n - 1; i++) {
        b.PB((a[i] * a[i + 1]) / (__gcd(a[i], a[i  + 1])));
    }
    int start = 1;
    bool flag = true;
    for(int i = 0; i < b.size() - 1; i++) {
        if(__gcd(b[i], b[i + 1]) != a[i + 1]) {
            flag = false;
        }
    }
    if(flag) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
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