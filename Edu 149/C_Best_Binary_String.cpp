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
    string s; cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '?') {
            if(i > 0 && i < s.length() - 1) {
                if(s[i - 1] == '1') {
                    s[i] = '1';
                }
                else if(s[i - 1] == '0') {
                    s[i] = '0';
                }                
            }
            else if(i == 0) {
                s[i] = '0';
            }
            else {
                s[i] = '1';
            }
        }
    }
    cout << s << '\n';
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