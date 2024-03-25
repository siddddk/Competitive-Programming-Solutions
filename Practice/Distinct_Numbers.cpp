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
    ll n;
    cin >> n;
    ll A[n];
    for(ll i = 0; i < n; i++) cin >> A[i];

    sort(A, A + n);

    ll counter = 0;

    for(ll i = 0; i < n; i++)
    {
        if(A[i] != A[i+1]) counter++;
    }

    cout << counter << "\n"; 
    return 0;
}