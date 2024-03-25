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
    ll T;
    cin >> T;
    ll answer = 0;
    ll powerOf5 = 5;
    ll toAdd = floor(T/powerOf5);
    for(ll i = 1; i < 15; i++)
    {
        toAdd = floor(T/powerOf5);
        if(floor(T/5) != 0)
        {
            answer += toAdd;
            
        }
        powerOf5 *= 5;
    }
    cout << answer << "\n";
    return 0;
}