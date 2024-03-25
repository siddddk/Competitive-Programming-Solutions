#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n;
    cin >> n;
    ll A[n];
    for(ll i = 0; i < n; i++)
    {
        cin >> A[i];
        if(A[i] < 0)
        {
            A[i] *= -1;
        }
    }

    ll minPositive = LLONG_MAX;
    ll maxNegative = LLONG_MIN;

    for(ll i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            
            if(minPositive > A[i])
                minPositive = A[i];
        }
        else
        {
            if(maxNegative < A[i])
                maxNegative = A[i];
        }
    }

    ll sum1 = 0;
    ll sum2 = 0;

    for(ll i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            sum2 += A[i];
        }
        else
        {
            sum2 -= A[i];
        } 
    }

    sum1  = sum2;

    sum1 -= 2*minPositive;
    sum1 += 2*maxNegative;

    ll answer = max(sum1, sum2);

    cout << answer << "\n";
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