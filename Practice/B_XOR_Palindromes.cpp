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

    int differences = 0;
    for(int i = 0; i < n / 2; i++) {
        if(s[i] != s[n - i - 1]) differences++;
    }
    // cout << differences << '\n';
    int nxt = differences;
    for(int i = 0; i <= n; i++) {
        if(i == nxt && nxt <= n - differences) {
            cout << '1';
            if(n & 1) {
                nxt += 1;
            }
            else nxt += 2;
        }
        else cout << '0';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        solve();
        cout << '\n';
    }
    return 0;
}