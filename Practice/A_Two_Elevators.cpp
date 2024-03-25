#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    int timeFirst = abs(1 - a);
    int timeSecond = abs(b- c) + abs(c - 1);
    if(timeFirst < timeSecond) {
        cout << 1 << "\n";
    } 
    else if(timeFirst > timeSecond) {
        cout << 2 << "\n";
    }
    else {
        cout << 3 << "\n";
    }
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