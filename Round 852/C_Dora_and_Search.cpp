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
    vector<int> aB = a;
    reverse(all(aB));
    if(is_sorted(all(a)) || is_sorted(all(aB))) {
        cout << -1 << "\n";
    }
    else {
        int i = 0, j = n - 1;
        int mx = n, mn = 1;
        while(((a[i] == mx || a[j] == mn) || (a[j] == mx || a[i] == mn)) && i <= j) {
            if(a[i] == mx) {
                i++;
                mx--;
            }
            else if(a[i] == mn) {
                i++;
                mn++;
            }

            if(a[j] == mx) {
                j--;
                mx--;
            }
            else if(a[j] == mn) {
                j--;
                mn++;
            }
        }
        if(i < j) {
            cout << i + 1 << " " << j + 1 << "\n";
        }
        else cout << -1 << "\n";
    }
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