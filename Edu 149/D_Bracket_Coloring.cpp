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
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') c1++;
        else c2++;
    }
    if(c1 != c2) {
        cout << -1 << '\n';
        return;
    }
    int i = 0;
    vector<int> c(n, 0);
    while(i < n) {
        stack<char> st;
        if(s[i] == '(') {
            for(; i < n; i++) {
                if(s[i] == '(') st.push(s[i]);
                else {
                    if(!st.empty()) st.pop();
                    else {
                        break;
                    }
                }
                c[i] = 1;
            }
        }
        else if(s[i] == ')') {
            for(; i < n; i++) {
                if(s[i] == ')') st.push(s[i]);
                else {
                    if(!st.empty()) st.pop();
                    else {
                        break;
                    }
                }
                c[i] = 2;
            }
        }
    }
    bool flag1 = false, flag2 = false;
    for(auto x : c) {
        if(x == 1) flag1 = true;
        else flag2 = true;
    }
    if(flag1 && flag2) {
        cout << 2 << '\n';
    }
    else {
        if(flag2) c.assign(n, 1);
        cout << 1 << '\n';
    }
    cout << c << '\n';
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