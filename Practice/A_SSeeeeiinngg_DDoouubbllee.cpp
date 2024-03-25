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
    string s; cin >> s;
    string sRev = s;
    reverse(sRev.begin(), sRev.end());
    for(int i = 0; i < sRev.length(); i++) {
        s += sRev[i];        
    }
    cout << s << "\n";
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