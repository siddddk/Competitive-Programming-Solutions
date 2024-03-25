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
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void solve(void) 
{
    int k; cin >> k;
    int ans = 0;
    ans += (k / 500);
    k -= 500*(k / 500);
    if(k > 400) {
        cout << ans + 1 << "\n";
        return;
    }
    ans += (k / 200);
    k -= 200*(k / 200);
    if(k > 100) {
        cout << ans + 1 << "\n";
        return;
    }
    ans += (k / 100);
    k -= 100*(k / 100);
    if(k > 0) ans++;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}