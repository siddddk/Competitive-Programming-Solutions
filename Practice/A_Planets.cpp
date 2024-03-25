#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n, c;
    cin >> n >> c;
    unordered_map<int, int> umap;
    int cost = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        umap[x]++;
    }

    for(auto x : umap) {
        cost += min(x.second, c);
    }
    cout << cost << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}