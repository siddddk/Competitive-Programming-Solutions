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

bool isB(string s) {
    bool blue  = true;
    bool red = true;
    bool flag = true;
    if(s.size() == 0) return false;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'R' && red) {
            red = false;
            blue = true;
        }
        else if(s[i] == 'B' && blue) {
            blue = false;
            red = true;
        }
        else {
            flag = false;
            break;
        }
    }
    return flag;
}

void solve(void) 
{
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    bool blue = false;
    if(isB(s) && isB(t)) {
        cout << "YES\n";
    }
    else {
        if(isB(s)) {
            while(!t.empty() && !isB(t)) {
                s += t.back();
                t.pop_back();
                // cout << s << " " << t << "\n";
            }
            if(isB(s) && isB(t)) {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
        else if(isB(t)) {
            while(!s.empty() && !isB(s)) {
                t += s.back();
                s.pop_back();
                // cout << s << " " << t << "\n";
            }
            if(isB(s) && isB(t)) {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
        else {
            cout << "NO\n";
        }
    }
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