#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;

int digitSum(int a) {
    int ans = 0;
    while(a != 0) {
        ans += (a % 10);
        a /= 10;
    }
    return ans;
}

void solve(void) {
    int n; cin >> n;
    if(n&1) {
        if(n % 10 == 9) {
            int nClone = n;
            nClone /= 10;
            if((nClone % 10)&1) {
                int a = n / 2;
                int b = n / 2 + 1;
                // cout << a << " " << b << "\n";
                int diff = digitSum(a) - digitSum(b);
                // cout << diff << "\n";
                a -= diff / 2;
                b += diff / 2;
                cout << a << " " << b << "\n";
            }
            else {
                cout << n / 2 << " " << (n / 2) + 1 << "\n";
            }
        }
        else {
            cout << n / 2 << " " << (n / 2) + 1 << "\n";
        }
    }
    else {
        cout << n / 2 << " " << n / 2 << "\n";
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