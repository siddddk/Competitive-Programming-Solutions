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
    ll x[n];
    for(ll i = 0; i < n; i++)
    {
      cin >> x[i];
    }
    
    ll minMoves = 0;
    
    for(ll i = 1; i < n; i++)
    {
        if(x[i] < x[i - 1])
        {
            minMoves += x[i-1] - x[i];
            x[i] = x[i - 1];
        }
    }
    
    cout << minMoves;
    return 0;
}