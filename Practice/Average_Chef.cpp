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
    int n, k; cin >> n >> k;
    vector<vector<int>> a (n / k);
    if(k % 2 == 0) {
        int start = 1;
        int counter = 0;
        while(a[0].size() != k) {
            if(counter % 2 == 0) {
                for(int i = 0; i < (n / k); i++) {
                    a[i].PB(start);
                    start++;
                }
                counter++;
            }
            else {
                for(int i = (n / k) - 1; i >= 0; i--) {
                    a[i].PB(start);
                    start++;
                }
                counter++;
            }
        }
        for(int i = 0; i < (n / k); i++) {
            cout << a[i];
        }
        cout << "\n";
    }
    else {
        int start = 1;
        int counter = 0;
        while(a[0].size() != k - 3) {
            if(counter % 2 == 0) {
                for(int i = 0; i < (n / k); i++) {
                    a[i].PB(start);
                    start++;
                }
                counter++;
            }
            else {
                for(int i = (n / k) - 1; i >= 0; i--) {
                    a[i].PB(start);
                    start++;
                }
                counter++;
            }
        }
        while(a[0].size() != k - 1) {
            for(int i = 0; i < (n / k); i++) {
                a[i].PB(start);
                start++;
            }
        }
        for(int i = (n / k) - 1; i >= 0; i--) {
            a[i].PB(start);
            start += 2;
        }
        for(int i = 0; i < (n / k); i++) {
            cout << a[i];
        }
        cout << "\n";
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