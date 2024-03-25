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
    map<char, int> m;
    for(int i = 0; i < n ; i++) m[s[i]]++;
    int maxFreq = 0;
    char maxChar;
    for(auto x : m) {
        if(x.S > maxFreq) {
            maxChar = x.F;
            maxFreq = x.S;
        }
    }
    string sAns (s.length(), maxChar);
    int ans = s.length() - maxFreq;
    int kAns = s.length();
    for(int i = 1; i < s.length(); i++) {
        string sC = s;
        if(n % i == 0) {
            int tempAns = 0, extra = 0;
            for(auto x : m) {
                if(x.S >= i) {
                    tempAns += x.S - i;
                }
                else extra += x.S;
            }
            tempAns += (extra / i);
            if(tempAns < ans) {
                ans = tempAns;
                kAns = i;
            }
        }
    }
    for(int i = s.length() - 1; i >= 1; i--) {
        if(m[s[i]] != kAns) {
            s[i] = s[i - 1];
            m[s[i]]--;
            m[s[i - 1]]++;
        }
    }
    cout << ans << "\n";
    cout << s << "\n";
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