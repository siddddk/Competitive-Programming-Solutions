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

void better(int &x, int y) {
    if(y >= 0 && (x < 0 || x > y)) {
        x = y;
    }
}

void addFactors(int a, unordered_set<int>& s) {
    for(int i = 2; i * i <= a; i++) {
        while(a % i == 0) {
            s.insert(i);
            a /= i;
        }
    }    
    if(a > 1) s.insert(a);
}

int rec(vector<int>& a, int x, int y) {
    unordered_set<int> s;
    addFactors(a[0] + 1, s);
    addFactors(a[0] - 1, s);
    addFactors(a[0], s);

    int ans = -1;

    for(auto p : s) {
        vector<int> dp = {a[0] % p ? y : 0, -1, -1};
        for(int i = 1; i < a.size(); i++) {
            vector<int> curr(3, -1);
            for(int j = 0; j < 3; j++) {
                if(dp[j] < 0) continue;

                if((a[i] % p == 0) || ((a[i] + 1) % p == 0) || ((a[i] - 1) % p == 0)) {
                    better(curr[j == 1 ? 2 : j], dp[j] + (a[i] % p ? y : 0));
                }

                if(j != 2) {
                    better(curr[1], dp[j] + x);
                }
            }
            dp = curr;
        }

        for(int i = 0; i < 3; i++) {
            better(ans, dp[i]);
        }
    }

    return ans;
}

void solve(void) 
{
    int m, x, y; cin >> m >> x >> y;
    vector<int> a(m); cin >> a;
    int ans = rec(a, x, y);
    reverse(a.begin(), a.end());
    better(ans, rec(a, x, y));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}