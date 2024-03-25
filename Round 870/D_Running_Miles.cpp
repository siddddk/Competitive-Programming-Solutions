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
    int n; cin >> n;
    vector<int> b(n); cin >> b;
    vector<int> pref(n, 0), suf(n, 0);
    for(int i = 0; i < n; i++) {
        pref[i] = b[i] + i + 1;
        if(i > 0) pref[i] = max(pref[i], pref[i - 1]);
        suf[i] = b[i] - i - 1;
    }    
    for(int i = n - 2; i >= 0; i--) {
        suf[i] = max(suf[i], suf[i + 1]);
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        ans = max(ans, pref[i - 1] + b[i] + suf[i + 1]);
    }
    cout << ans << '\n';
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