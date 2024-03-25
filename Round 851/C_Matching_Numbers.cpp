#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;


void solve(void) {
    int n; cin >> n;
    if(n&1) {
        cout << "YES\n";
        int a = 1;
        int b = (3*(n + 1)) / 2;
        b--;
        int counter = 0;
        int prev;
        while(a < b && counter < n) {
            prev = a + b;
            cout << a << " " << b << "\n";
            counter++;
            a += 2;
            b--;
        }
        a = 2;
        b = prev + 1 - 2;
        while(a < b && counter < n) {
            cout << a << " " << b << "\n";
            counter++;
            a += 2;
            b--;
        }
    }
    else {
        cout << "NO" << "\n";
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