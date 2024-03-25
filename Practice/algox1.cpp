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
    string s; cin >> s;
    bool flag = false;
    for(int i = 0; i < n - 9; i++) {
        if(s.substr(i, 10) == "AlgoManiaX") flag = true;
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}