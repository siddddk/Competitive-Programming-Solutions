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
    int ans = 0;
    vector<int> sieve(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        if(sieve[i] != 0) continue;
        for(int j = i; j <= n; j += i) {
            sieve[j]++;
        }
    }
    // cout << sieve << "\n";
    for(int i = 1; i <= n; i++) {
        if(sieve[i] == 2) {
            ans++;
            // cout << i << "\n";
        }
    }
    cout << ans << "\n";
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}