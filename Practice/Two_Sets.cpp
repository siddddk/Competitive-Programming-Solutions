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
 
    if((n*(n+1)/2) % 2 == 0 && n < 10000)
    {
        cout << "YES" << "\n";
        ll a = n;
        ll counter = 0;
        ll addEnd = n - 1;
        ll counter2 = 1;
        while(!counter)
        {
            if(a == (n*(n+1) / 4))
            {
                counter++;
                cout << 1 << "\n";
                cout << n << "\n";
                cout << n - 1 << "\n";
                for(int k = 1; k < n; k++)
                {
                    cout << k << " ";
                }
                cout << "\n";
                return 0;                
            }
            for(ll i = 1; i <= addEnd; i++)
            {
                if(a + i == (n*(n+1) / 4))
                {
                    counter++;
                    cout << n - addEnd + 1 << "\n";
                    cout << i << " ";
                    for(int k = n; k > addEnd; k--)
                    {
                        cout << k << " ";
                    }
                    cout << "\n";
                    cout << addEnd - 1 << "\n";
                    for(int k = 1; k <= addEnd; k++)
                    {
                        if(k != i)
                        {
                            cout << k << " ";
                        }
                    }
                    cout << "\n";
                    return 0;
                }
            }
 
            a += addEnd;
            addEnd--;
            counter2++;            
        }
    }
    else if((n*(n+1)/2) % 2 == 0 && n >= 10000)
    {
        cout << "YES" << "\n";
        ll a = n;        
        ll limit = ceil(n/2);
        ll count = 1;

        for(ll i = 1; i < limit; i++)
        {
            a += n - i;
            ll lastAdded = n - i;
            count++;
            if(n*(n+1)/4 - a < limit)
            {
                for(ll j = limit; j >= 1; j--)
                {
        
                    if(a + j == n*(n+1)/4)
                    {
                        cout << count + 1 << "\n";
                        cout << j << " ";
                        for(ll p = 0; p < count; p++)
                        {
                            cout << n - p << " ";
                        } 
                        cout << "\n";

                        cout << n - count - 1 << "\n";
                        for(ll q = 1; q < lastAdded; q++)
                        {
                            if(q != j)
                            {
                                cout << q << " ";
                            }
                            cout << "\n";
                        }


                        return 0;
                    }
                }             
            }
        }       
    }
    else
    {
        cout << "NO" << "\n";
    }
    return 0;
}