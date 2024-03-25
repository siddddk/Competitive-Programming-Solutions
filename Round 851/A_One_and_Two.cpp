#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;

int highestPow2(int n) {
    return log2(n & (~(n - 1)));
}
 
bool isPowerOfTwo(int x) {
    return x && (!(x & (x - 1)));
}

void solve(void) {
    int n; cin >> n;
    vector<int> a(n, 0);
    int twoCount = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 2) twoCount++;
    }
    if(twoCount % 2 == 0) {
        int counter = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 2) counter++;
            if(counter == twoCount / 2) {
                ans = i;
                break;
            }
        }
        cout << ans + 1 << "\n";
    }
    else {
        cout << -1 << "\n";
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