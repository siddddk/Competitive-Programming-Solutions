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
    vector<int> a(n, 0), pos(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int i = (n + 1) / 2;
    int j = (n + 2) / 2;
    int count = 0;
    while(i > 0 && (i == j || (pos[i] < pos[i + 1] && pos[j - 1] < pos[j]))) {
        // cout << i << " < " << i + 1 << " and " << j - 1 << " < " << j << "\n";
        count++;
        i--;
        j++;
    }
    if(n&1) count--;
    cout << (n / 2) - count << "\n";
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