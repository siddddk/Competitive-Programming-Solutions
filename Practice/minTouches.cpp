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
int dp[101][1 << 12];
vector<string> v;

int rec(int n, int mask) {

}

void solve(void) {
  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    v.PB(s);
  }
  memset(dp, -1, sizeof(dp));
  int mask = (1 << 11);
  mask--;
  cout << rec(n, mask) << "\n";
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