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
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void solve(void) 
{
    int n; cin >> n;
    vector<int> a (n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    // cout << a << "\n";
    multiset<int> m;
    for(int i = 0; i < n; i++) {
        auto it = m.lower_bound(a[i]);
        if(it != m.begin()) it--;
        if(it != m.end() && (*it + 1 == a[i])) {
            // cout << *it << " erased " << " for " << a[i] << "\n";
            m.erase(it);                
        }
        m.insert(a[i]);
    }
    cout << m.size() << "\n";
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