#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
int counter = 0;
void search(vector<int> P, int n, int k)
{
    if(n == k)
    {
        for(int i = 0; i < P.size(); i++)
        {
            cout << P[i];
        }
        cout << "\n";
    }    
    else
    {
        P.PB(0);
        search(P, n+1, k);        
        P.pop_back();

        P.PB(1);
        search(P, n+1, k);
        P.pop_back();

        P.PB(2);
        search(P, n+1, k);             
        P.pop_back();        
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> A;
    search(A, 0, n);
    cout << counter << "\n";
    counter = 0;
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}