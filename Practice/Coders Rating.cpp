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

void update(int index, int n) {
    for(;index <= n; index += index & (-index)) {
        bit[index]++;
    }
}

int query(int index) {
    int sum = 0;
    for(;index > 0; index -= index & (-index)) {
        sum += bit[index];
    }
    return sum;
}

void solve(void) 
{
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    bit.assign(100001, 0);
    map<pair<int, int>, int> id;
    for(int i = 0; i < n; i++) {
        cin >> a[i].F >> a[i].S;
        id[a[i]] = i;
    }
    sort(all(a));
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        int e = i;
        while(e < n && a[i].S == a[e].S && a[i].F == a[e].F) e++;
        for(int j = i; j < e; j++) {
            ans[id[a[i]]] = query(a[i].S);
        }
        for(int j = i; j < e; j++) {
            update(a[i].S, 100000);
        }        
        i = e;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}