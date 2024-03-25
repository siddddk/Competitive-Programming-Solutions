#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
 
 
void solve(void)
{
    string s;
    cin >> s;
    string g = "";
    string h = "";
    for(int i = s.length() - 1; i >= 0; i--) {
        if(g.empty() || s[i] <= g[g.size() - 1]) {
            g += s[i];
        }
        else {
            if(s[i] == '9') {
                h += s[i];
            }
            else {
                h += ++s[i];
            }
        }
    }
    
    g += h;
    sort(g.begin(), g.end());
    cout << g << "\n";
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