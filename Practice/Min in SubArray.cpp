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

int queryTree(vector<int>& tree, int s, int e, int idx, int l, int r) {
    if(s > r || e < l) {
        return INT_MAX;
    }

    if(s >= l && e <= r) {
        return tree[idx];
    }

    int m = (s + e) >> 1;
    int ans1 = queryTree(tree, s, m, 2 * idx + 1, l, r);
    int ans2 = queryTree(tree, m + 1, e, 2 * idx + 2, l, r);
    return min(ans1, ans2);
}

void updateTree(vector<int>& a, vector<int>& tree, int s, int e, int treeNode, int idx) {
    if(s == e) {
        tree[treeNode] = a[s];
        return;
    }

    int m = (s + e) >> 1;
    if(idx <= m) updateTree(a, tree, s, m, 2 * treeNode + 1, idx);
    else updateTree(a, tree, m + 1, e, 2 * treeNode + 2, idx);

    tree[treeNode] = min(tree[2 * treeNode + 1], tree[2 * treeNode + 2]);
}

void buildTree(vector<int>& a, vector<int>& tree, int s, int e, int idx) {
    if(s == e) {
        tree[idx] = a[s]; 
        return;
    }
    
    int m = (s + e) >> 1;
    buildTree(a, tree, s, m, 2 * idx + 1);
    buildTree(a, tree, m + 1, e, 2 * idx + 2);

    tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
}

void solve(void) 
{
    int n, q; cin >> n >> q;
    vector<int> a(n); cin >> a;
    vector<int> tree(4*n);

    buildTree(a, tree, 0, n - 1, 0);
    
    while(q--) {
        char c; cin >> c;
        if(c == 'q') {
            int l, r; cin >> l >> r;
            --l; --r;
            cout << queryTree(tree, 0, n - 1, 0, l, r) << '\n';
        }
        else {  
            int i, b; cin >> i >> b;
            --i;
            a[i] = b;
            updateTree(a, tree, 0, n - 1, 0, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}