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
    int c1 = 0, c2 = 0;
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == '>' && s[i - 1] == '>') {
            c1++;
        }
        else {
            ans = max(c1 + 2, ans);
            c1 = 0;
        }

        if(s[i] == '<' && s[i - 1] == '<') {
            c2++;
        }
        else {
            ans = max(c2 + 2, ans);
            c2 = 0;
        }
    }

    ans = max(c1 + 2, ans);
    ans = max(c2 + 2, ans);

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