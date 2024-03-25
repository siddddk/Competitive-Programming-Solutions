#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;

int m[1 << 26];
void solve(void) 
{
    int n; cin >> n;
    int N = (1 << 26);
    N--;
    vector<int> contains(n, 0);
    vector<int> mask(n, 0);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(char c : s) {
            contains[i] |= (1 << (c - 'a'));
            mask[i] ^= (1 << (c - 'a'));
        }
    }
    ll ans = 0;
    for(int i = 0; i < 26; i++) {
        memset(m, 0, sizeof(m));
        int XOR = N ^ (1 << i);
        for(int j = 0; j < n; j++) {
            if(contains[j] & (1 << i)) continue;
            ans += m[mask[j] ^ XOR];
            m[mask[j]]++;
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