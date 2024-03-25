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
    string s; cin >> s;
    int player = 0;
    int dir = 1;
    for(int i = 0; i < k; i++) {
        if(s[i] == 'U') player += dir;
        else if(s[i] == 'S') player += 2 * dir;
        else {
            dir *= -1;
            player += dir;
        }

        if(player >= n) player = (player % n);
        else if(player < 0) {
            player = n + player;
        }

        // cout << player << ' ';
    }
    // cout << '\n';

    cout << player + 1;
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