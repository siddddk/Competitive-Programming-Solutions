#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void solve(void)
{
    int n; cin >> n;
    vector<int> a(n, 0); cin >> a;
    int mn = 0, mx = (int)1e9;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] < a[i + 1]) {
            mx = min(mx, ((a[i] + a[i + 1]) / 2));
        }
        else if(a[i] > a[i + 1]) {
            mn = max(mn, ((a[i] + a[i + 1] + 1) / 2));
        }
    }
    if(mn <= mx) {
        cout << mn << "\n";          
    }
    else cout << -1 << "\n"; 
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