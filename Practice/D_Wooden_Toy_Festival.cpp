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

bool ok(int x, vector<int>& a) {
    int n = a.size();
    int i = 0, j = n - 1;

    while(i < a.size() && a[i] - a[0] <= 2*x) i++;

    while(j >= 0 && a[n - 1] - a[j] <= 2*x) j--;

    if(i > j || a[j] - a[i] <= 2 * x) return true;
    else return false;
}

void solve(void) 
{
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    sort(all(a));
    int l = -1, r = 1e9;

    while(r - l > 1) {
        int m = (l + r) / 2;

        if(ok(m, a)) {
            r = m;
        }
        else l = m;
    } 

    cout << r;   
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