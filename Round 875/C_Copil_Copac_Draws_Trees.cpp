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

vector<bool> vis;
vector<vector<pair<int, int>>> adj;

int dfs(int s, int time, int level) {
    vis[s] = true;
    int ans = level;
    for(auto x : adj[s]) {
        if(!vis[x.first]) {
            if(x.second < time) {
                ans = max(ans, dfs(x.first, x.second, level + 1));
            }
            else ans = max(ans, dfs(x.first, x.second, level));
        }
    }
    return ans;
}

void solve(void) 
{
    int n; cin >> n;
    vector<pair<int, int>> edges;
    vis.clear();
    vis.assign(n, false);
    adj.clear();
    adj.resize(n);
    vector<int> first(n, -1);
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        if(first[a] == -1) {
            first[a] = i;
        }
        if(first[b] == -1) {
            first[b] = i;
        }
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    cout << dfs(0, first[0], 1) << '\n';
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