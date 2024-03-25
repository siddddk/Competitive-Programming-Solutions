#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    bool flag = false;
    for(int i = 0; i < 8; i++) {
        string s; cin >> s;
        if(s == "RRRRRRRR") {
            flag = true;
        }
    }
    if(flag) cout << "R";
    else cout << "B";
    cout << "\n";
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