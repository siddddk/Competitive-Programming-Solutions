#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n; cin >> n;
    string s; cin >> s;
    string t = "0";
    t += s;
    ll cost = 0;
    unordered_map<int, bool> vis;
    for(int i = 1; i <= n; i++) vis[i] = false;
    for(int i = 1; i <= n; i++) {
        if(t[i] == '0') {
            for(int j = i; j <= n; j += i) {
                if(t[j] == '0') {
                    if(!vis[j]) cost += i;
                    vis[j] = true;
                } else break;
            }
        }
    }
    cout << cost << "\n";
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