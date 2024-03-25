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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    string sClone = s;
    string tClone = t;
    sort(sClone.begin(), sClone.end()); sort(tClone.begin(), tClone.end());
    if(sClone != tClone) {
        cout << "NO\n";
        return;
    }
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'b') continue;
        else {
            while(t[j] == 'b') j++;

            if((s[i] != t[j]) || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j)) {
                cout << "NO\n";
                return;
            }
            j++;
        }
    }
    cout << "YES\n";    
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