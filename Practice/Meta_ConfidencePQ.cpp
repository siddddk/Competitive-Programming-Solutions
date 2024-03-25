#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

void solve(void)
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans(n, 1);
    for(int i = 0; i <= n - 2; i++) {
        pq.push({a[i], i});
        while(!pq.empty() && pq.top().first < a[i + 1]) {
            ans[pq.top().second] = i + 1 - pq.top().second;
            pq.pop();
        }
    }
    while(!pq.empty()) {
        ans[pq.top().second] = n - pq.top().second;
        pq.pop();
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}