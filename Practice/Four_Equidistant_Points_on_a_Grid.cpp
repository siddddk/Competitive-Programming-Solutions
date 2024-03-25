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
    ll d;
    cin >> d;

    if(d == 1 || d % 2 != 0)
    {
        cout << -1;
    }
    else
    {
        ll num = d/2+1;
        cout << 0 << " " << 0 << "\n";
        cout << d << " " << 0 << "\n";
        cout << d/2 << " " << d/2 << "\n";
        cout << d/2 << " " << -d/2 << "\n"; 
    }
    return 0;
}