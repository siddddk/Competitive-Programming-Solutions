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

void update(int num, int val) {
    for(; num <= 100000; num += num & (-num)) {
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
    int n; cin >> n;
    bit.assign(100001, 0);
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(all(a));
    int q; cin >> q;
    vector<tuple<int, int, int, int>> queries;
    for(int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k;
        queries.push_back({k, l, r, i});
    }
    sort(all(queries));
    vector<int> ans(q);
    int j = n - 1;
    for(int i = q - 1; i >= 0; i--) {
        while(j >= 0 && a[j].first > get<0>(queries[i])) {
            update(a[j].second, 1);
            j--;
        }
        ans[get<3>(queries[i])] = query(get<2>(queries[i])) - query(get<1>(queries[i]) - 1);
    }

    for(auto x : ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}