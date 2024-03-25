#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n;
    cin >> n;
    int cnt[n];
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        cin >> cnt[i];
        pq.push(cnt[i]);
    }
    for(int i = 0; i < n; i++) {
        if(cnt[i] == pq.top()) {
            cout << i + 1 << "\n";
            return;
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}