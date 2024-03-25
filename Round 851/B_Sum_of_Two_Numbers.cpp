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
    string s; cin >> s;
    string x = "";
    string y = "";
    int diff = 0;
    bool flag = true;
    for(int i = 0; i < s.length(); i++) {
        int d = s[i] - '0';
        if(d % 2 == 0) {
            x += '0' + d / 2;
            y += '0' + d / 2;
        }
        else if(flag) {
            x += (d - d / 2) + '0';
            y += d / 2 + '0';
            flag = false;
        }
        else {
            x += d / 2 + '0';
            y += (d - d / 2) + '0';
            flag = true;
        }
    }
    int ans1 = stoi(x);
    int ans2 = stoi(y);
    cout << ans1 << " " << ans2 << "\n";

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