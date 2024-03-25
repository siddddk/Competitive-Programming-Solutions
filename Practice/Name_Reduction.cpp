#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    string A, B;
    cin >> A >> B;
    ll n;
    cin >> n;
    string C[n];
    ll counter = 0;
    while(n--)
    {
        cin >> C[counter];
        while (C[counter].length()==0 )
            getline(cin, C[counter]);
        counter++;
    }
    string AplusB= A+B;
    ll alphabetCountAB[26] = {0};
    for(ll i = 0; i < AplusB.length(); i++)
    {
        alphabetCountAB[AplusB[i] - 97]++;
    }
    ll alphabetCountC[26] = {0};
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < C[i].length(); j++)
        {
            alphabetCountC[C[i][j] - 97]++;
        }
    }
    cout << alphabetCountAB[1] << "\n";
    cout << alphabetCountC[0] << "\n";
    for(ll i = 0; i < 26; i++)
    {
        if(alphabetCountAB[i] <= alphabetCountC[i])
        {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
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