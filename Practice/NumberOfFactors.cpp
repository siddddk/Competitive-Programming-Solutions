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

int sieve[1000001];

void solve(void) 
{
    int a, b, n; cin >> a >> b >> n;
    int ans = 0;
    for(int i = a; i <= b; i++) {
        if(sieve[i] == n) ans++;
    }
    cout << ans << "\n";
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(sieve, 0, sizeof(sieve));
    for(int i = 2; i <= 1000000; i++) {
        if(sieve[i] != 0) continue;
        for(int j = i; j <= 1000000; j += i) {
            sieve[j]++;
        }
    }
    int t; cin >> t;
    while(t--) solve();
    return 0;
}