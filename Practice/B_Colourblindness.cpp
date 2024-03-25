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
    string row1, row2;
    cin >> row1 >> row2;
    for(int i = 0; i < n; i++) {
        if(row1[i] == 'G') {
            row1[i] = 'B';
        }

        if(row2[i] == 'G') {
            row2[i] = 'B';
        }
    }
    if(row1 == row2) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    return;
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