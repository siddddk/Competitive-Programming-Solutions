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
    int q; cin >> q;
    vector<int> v;
    string ans = "";
    bool flag = false;
    for(int i = 0; i < q; i++) {
        int x; cin >> x;
        bool append = false;
        if(v.size() == 0) append = true;
        else {
            if(!flag) {
                if(x >= v.back()) append = true;
                else if(x <= v[0]) {
                    append = true;
                    flag = true;
                }
            }
            else {
                if(x >= v.back() && x <= v[0]) append = true;
            }
        }
        if(append) {
            ans += '1';
            v.push_back(x);
        }
        else ans += '0';
    }
    cout << ans;
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