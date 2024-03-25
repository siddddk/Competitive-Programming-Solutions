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
    vector<int> a(n); cin >> a;
    if(*max_element(all(a)) == *min_element(all(a))) {
        cout << 1 << "\n";
        return;
    }
    int i = 0, j = 1;
    int ans = 1;
    while(j < n) {
        int j1 = j, j2 = j, temp = j;
        while(a[j1 - 1] <= a[j1] && j1 < n) j1++;

        while(a[j2 - 1 ] >= a[j2] && j2 < n) j2++;

        j = max(j1, j2);
        ans++;
        i = j - 1;
    }
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
