#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
 
 
void solve(void)
{
    int n;
    cin >> n;
    vector<int> songs(n, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> songs[i];
    set<int> s;
    int r = -1;
    for(int i = 0; i < n; i++) {
        while(r < n - 1 && !s.count(songs[r + 1])) s.insert(songs[++r]);
        ans = max(ans, r - i + 1);
        s.erase(songs[i]);
    }
    cout << ans << "\n";
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}