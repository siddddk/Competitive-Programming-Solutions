#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long ll;
using namespace std;

int factmod(int n, int p)
{
    if (n >= p)
        return 0;
 
    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result * i) % p;
 
    return result;
}

void solve(void)
{
    int n, p; cin >> n >> p;
    if(n&1) {
        cout << factmod(n, p) / 2;
    }
    else {
        cout << (((n*(n - 2))*factmod(n - 2, p)) / 2) + factmod(n - 2, p)*n;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}