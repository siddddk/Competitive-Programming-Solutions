#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll A[n];
    for(ll i = 0; i < n; i++) cin >> A[i];

    ll maxSoFar = A[0];
    ll minSum = 0;
    ll ans = A[0];
    ll sum = 0;

    for(ll i = 0; i < n; i++)
    {
        sum += A[i];
        ans = max(ans, sum - minSum);
        minSum = min(sum, minSum);        
    }

    cout << ans << "\n";
        

    return 0;
}