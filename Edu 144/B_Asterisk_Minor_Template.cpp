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
    string a, b; cin >> a >> b;
    if(a[0] == b[0]) {
        cout << "YES\n";
        cout << a[0] << '*' << "\n";
        return;
    }
    else if(a.back() == b.back()) {
        cout << "YES\n";
        cout << '*' << a.back() << "\n";
        return;
    }
    else {
        for(int i = 0; i < a.length() - 1; i++) {
            string s = a.substr(i, 2);
            for(int j = 0; j < b.length() - 1; j++) {
                if(b.substr(j, 2) == s) {
                    cout << "YES\n";
                    cout << '*' << b.substr(j, 2) << '*' << "\n";
                    return;
                }
            }
            // cout << a.substr(i, 2) << "\n";
        }
    }
    cout << "NO\n";
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