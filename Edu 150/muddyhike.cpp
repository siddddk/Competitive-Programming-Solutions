#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
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
    ll m, n; cin >> m >> n;
    vector<vector<ll>> g (m, vector<ll>(n));
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for(ll i = 0; i < m; i++) cin >> g[i];

    ll mxdist = LLONG_MIN;
    for(ll i = 0; i < m; i++) {
        for(ll j = 0; j < n; j++) mxdist = max(mxdist, g[i][j]);
    }
    vector<vector<ll>> dist(m, vector<ll>(n, mxdist));
    ll dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> q;
    for(ll i = 0; i < m; i++) {
        dist[i][0] = g[i][0];
        q.push({g[i][0], i, 0});
    }
    while(!q.empty()) {
        tuple<ll, ll, ll> curr = q.top(); q.pop();
        ll r = get<1>(curr), c = get<2>(curr), d = get<0>(curr);

        if(dist[r][c] < d) continue;

        for(ll i = 0; i < 4; i++) {
            ll x = r + dx[i], y = c + dy[i];
            if(x < 0 || x >= m || y < 0 || y >= n) continue;
            if(max(d, g[x][y]) < dist[x][y]) {
                dist[x][y] = max(d, g[x][y]);
                q.push({max(d, g[x][y]), x, y});
            }
        }
    }
    ll ans = mxdist;
    for(ll i = 0; i < m; i++) ans = min(ans, dist[i][n - 1]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}