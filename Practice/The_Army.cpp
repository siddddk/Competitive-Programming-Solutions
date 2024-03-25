#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
void solve(void)
{
    ll n, m;
    cin >> n >> m;
    ll arrM[m];
    for(ll i = 0; i < m; i++)
    {
        cin >> arrM[i];
    }
    sort(arrM, arrM+m);
    ll count  = 1;
    for(ll i = 0; i < n; i++)
    {
        cout << max(arrM[m-1] - i, i - arrM[0]) << " ";
    }

    cout << "\n";
    return;    
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