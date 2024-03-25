#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef unsigned long long ll;
using namespace std;


void solve(void)
{
    ll i, j;
    cin >> i >> j;

    if(max(i, j) == i)
    {
        if(i % 2 == 0)
        {
            ll answer = i*i;
            answer -= j;
            answer++;
            cout << answer;
            cout << "\n";
        }
        else
        {
            i--;
            ll answer = i*i;
            answer += j;
            cout << answer;
            cout << "\n";
        }
    }
    else
    {
        if(j % 2 != 0)
        {
            ll answer = j*j;
            answer -= i;
            answer++;
            cout << answer;
            cout << "\n";
        }
        else
        {
            j--;
            ll answer = j*j;
            answer += i;
            cout << answer << "\n";
            cout << "\n";
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