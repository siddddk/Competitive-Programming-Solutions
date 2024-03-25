#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;



void solve(void)
{
    int n, a, b; cin >> n >> a >> b;
    int time = 0;
    for(int i = 1; i < log2(n); i++) {
        time += a;
        time += b;
    }
    time += a;

    cout << time << "\n";
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