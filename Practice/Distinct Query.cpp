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

vector<int> bit;

void update(int num, int n, int val) {
    for(; num <= n; num += num & (-num)) {
        bit[num] += val;
    }
}

int query(int num) {
    int ans = 0;
    for(; num > 0; num -= num & (-num)) {
        ans += bit[num];
    }
    return ans;
}

void solve(void) 
{
    int n, q; cin >> n >> q;
    vector<int> a(n + 1); 
    for(int i = 1; i <= n; i++) cin >> a[i];
    bit.assign(n + 1, 0);
    vector<vector<pair<int, int>>> queries(n + 1);
    unordered_map<int, int> lastIdx;
    vector<int> ans(q);
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        queries[b].push_back({a, i});
    }
    int distinct = 0;
    for(int i = 1; i <= n; i++) {
        if(lastIdx.count(a[i])) {
            update(lastIdx[a[i]], n, -1);
        }
        else distinct++;

        update(i, n, 1);
        lastIdx[a[i]] = i;

        for(auto x : queries[i]) {
            ans[x.second] = distinct - query(x.first - 1);
        }
    }

    for(auto x : ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}