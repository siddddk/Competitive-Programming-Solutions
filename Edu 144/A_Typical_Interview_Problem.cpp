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
    string s; cin >> s;
    string fbStr = "";
    for(int i = 3; i <= 300; i++) {
        if(i % 3 == 0) {
            fbStr += 'F';
        }
        if(i % 5 == 0) {
            fbStr += 'B';
        }
    }
    bool flag = false;
    for(int i = 0; i < fbStr.length() - k - 1; i++) {
        if(fbStr.substr(i, k) == s) flag = true;                
    }
    if(flag) cout << "YES\n";
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