#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
void solve(ll n)
{
    ll answer = ((n*n*(n*n-1))/2 - 4*(n-1)*(n-2));
    cout << answer << "\n";
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        solve(i);        
    }   

    return 0;
}