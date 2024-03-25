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
    ll sum = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];
    }

    ll answer[n];
    answer[0] = A[0];

    for(ll i = 1; i < n; i++)
    {
        answer[i] = answer[i-1] + A[i];    
    }
    ll nextAnswer[n];
    for(ll i = 0; i < n; i++)
    {
        nextAnswer[i] = max(answer[i], sum - answer[i]);
    }

    ll min = INT_MAX;

    for(ll i = 0; i < n; i++)
    {
        if(nextAnswer[i] < min)
        {
            min = nextAnswer[i];
        }
    }

    cout << min << "\n";
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