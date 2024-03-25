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
    string s; cin >> s;
    int j = n / 2;
    if(n&1) j++;
    int i;
    if(n&1) i = j - 2;
    else i = j - 1; 
    bool flag = false;
    bool flag2 = true;
    bool ans = true;
    // cout << i << " " << j << "\n";
    while(i >= 0 && j < n) {
        // cout << s[i] << " " << s[j] << "\n";
        if(flag) {
            if(s[i] == s[j] && flag2) {
                flag2 = false;
            }
            if(s[i] != s[j] && !flag2) {
                ans = false;
                break;
            }            
        }
        else {
            if(s[i] != s[j]) {
                flag = true;
            }
        }
        i--;
        j++;
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
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