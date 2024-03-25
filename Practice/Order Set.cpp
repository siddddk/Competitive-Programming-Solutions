#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;

vector<int> bit;

void update(int idx, int val) {
    for(; idx <= 200000; idx += idx & (-idx)) {
        bit[idx] += val;
    }
}

int query(int idx) {
    int ans = 0;
    for(; idx > 0; idx -= idx & (-idx)) {
        ans += bit[idx];
    }
    return ans;
}

void solve(void) 
{
    int q; cin >> q;
    vector<pair<char, int>> queries;
    set<int> s; 
    while(q--) {
        char op; cin >> op;
        int i; cin >> i;
        queries.push_back({op, i});
        if(op != 'K') s.insert(i);
    }
    unordered_map<int, int> id, rev;
    int cnt = 1;
    for(auto x : s) {
        id[x] = cnt;
        rev[cnt] = x;
        cnt++;
    }
    bit.assign(200001, 0);
    for(auto x : queries) {
        char op = x.first;
        int i;
        if(id.count(x.second)) i = id[x.second];
        int k = x.second;
        if(op == 'I') {
            if(query(i) == query(i - 1)) {
                update(i, 1);
            }
        }
        else if(op == 'D') {
            if(query(i) != query(i - 1)) {
                update(i, -1);
            }
        }
        else if(op == 'K') {
            int l = 0, r = 200001, ans;
            bool flag = false;
            while(l <= r) {
                int m = (l + r) >> 1;
                if(query(m) == k && query(m - 1) != k) {
                    flag = true;
                    ans = m;
                    break;
                }
                else if(query(m) < k) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            if(!flag) cout << "invalid\n";
            else cout << rev[ans] << '\n';
        }
        else {
            if(query(i) == query(i - 1)) {
                cout << query(i) << '\n';
            }
            else cout << query(i) - 1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}