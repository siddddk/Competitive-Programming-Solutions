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
    int cost = 0;
    for(int i = 1; i < n; i++) {
        if((a[i] % (2*a[0] - 1)) == 0) {
                cost += (a[i] / (2*a[0] - 1)) - 1;
        }
        else {
            cost += (a[i] / (2*a[0] - 1));
        }
    }
    cout << cost << "\n";
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