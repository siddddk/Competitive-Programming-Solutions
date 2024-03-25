#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

ll maxSubArraySum(ll a[], ll size)
{
    ll max_so_far = LLONG_MIN, max_ending_here = 0;
 
    for (ll i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

void solve(void)
{
    ll n, k;
    cin >> n >> k;
    ll A[n];
    ll counter = 0;
    ll maxSumA = 0;
    ll sumOfA = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> A[i];
        if(A[i] > 0)
            counter++;
        
        sumOfA += A[i];        
    }

    if(counter == n)
    {
        ll A = sumOfA*k;
        cout << A << "\n";
        return;
    }

    if(k == 1)
    {
        ll A2 = maxSubArraySum(A, n);
        cout << A2 << "\n";
        return;
    }

    maxSumA = maxSubArraySum(A, n);

    ll B[2*n];

    for(ll i = 0; i < n; i++)
    {
        B[i] = A[i];
    }

    for(ll i = n; i < 2*n; i++)
    {
       B[i] = A[i-n];
    }

    ll maxSumB = maxSubArraySum(B, 2*n);

    ll toCompare = max(sumOfA*k, maxSumB);

    ll caseWhichIDidNotConsider = maxSumA + sumOfA*(k-2);

    ll A3 = max(toCompare, maxSumA);

    ll A4 = max(A3, caseWhichIDidNotConsider);

    cout << A4 << "\n";
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