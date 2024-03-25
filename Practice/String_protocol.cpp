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
    string S;
    cin >> S;

    ll counter = 0;

    for(ll i = 0; i < n; i++)
    {
        if(S[i] == S[i+1])
        {
            counter++;
            i ++;
        }
        else
        {
            counter++;
        }
    }

    cout << counter << "\n";
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