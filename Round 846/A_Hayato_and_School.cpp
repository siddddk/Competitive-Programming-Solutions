#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;


void solve(void)
{
    int n; cin >> n;
    vector<int> a (n, 0);
    vector<int> e, o;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]&1) o.PB(i + 1);
        else e.PB(i + 1);
    }
    if(o.size() >= 3) {
        cout << "YES\n";
        cout << o[0] << " " << o[1] << " " << o[2] << "\n";
    } 
    else if(o.size() >= 1 && e.size() >= 2) {
        cout << "YES\n";
        cout << o[0] << " " << e[0] << " " << e[1] << "\n";
    }
    else {
        cout << "NO\n";
    }

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