#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void towerOfHanoi(int n, int a, int b, int c)
{
    if(n == 0)
    {
        return;
    }
    
    towerOfHanoi(n-1, a, c, b);

    cout << a << " " << c << "\n";

    towerOfHanoi(n-1, b, a, c);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << pow(2, n) - 1 << "\n";
    towerOfHanoi(n, 1, 2, 3);
    return 0;
}