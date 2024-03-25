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
    }
    string S;
    cin >> S;

    ll B[n];
    for(ll i = 0; i < n; i++)
    {
        B[i] = A[i];
    }

    sort(B, B+n);
    ll counter = 0;
    ll counter2 = 0;
    ll min = n+2;
    ll max = -1;
    for(ll i = 0; i < n; i++)
    {
        if(B[i] == A[i])
        {
            counter++;
        }
        else
        {
            if(i < min)
            {
                min = i;
            }
            else if(i > max)
            {
                max = i;
            }
        }
    }

    for(ll i = 0; i <= min; i++)
    {
        for(ll j = max; j <= n; j++)
        {
            if(abs(S[i] - S[j]) == 5)
            {
                counter2++;
            }
        }
    }


    if(counter == n)
    {
        cout << 0 << "\n";
        return;
    }

    ll ifSort = 0;

    for(ll i = 0; i < n; i++)
    {
        ifSort += S[i];
    }

    if(ifSort == 78*n || ifSort == 83*n)
    {
        cout << -1 << "\n";
        return;
    }

    if(S[0] == 'N' && S[n-1] == 'S')
    {
        cout << 1 << "\n";
        return;
    }
    else if(S[0] == 'S' && S[n-1] == 'N')
    {
        cout << 1 << "\n";
        return;
    }
    else
    {
        if(counter2)
        {
            cout << 1 << "\n";
            return;
        }
        else
        {
            cout << 2 << "\n";
            return;
        }
    }
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