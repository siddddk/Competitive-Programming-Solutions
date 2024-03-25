#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll N;
    cin >> N;
    ll numEven = 2;
    ll numOdd = 1;
    for(int i = 0; i < N; i++)
    {
        if(i % 2 == 0)
        {
            cout << numEven << " ";
            numEven += 2;
        }
        else
        {
            cout << numOdd << " ";
            numOdd += 2;
        }
    }
    cout << "\n";
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}