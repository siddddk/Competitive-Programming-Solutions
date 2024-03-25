#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, q;
    cin >> n >> q;
    string A;
    cin >> A;
    string B;
    cin >> B;

    ll q1, q2;
    for(ll i = 0; i < q; i++)
    {
        cin >> q1 >> q2;
        if(q1 == q2)
        {
            cout << "YES" << "\n";
            continue;
        }
        string a = "";
        string b = "";
        ll count = 0;
        for(ll i = q1-1; i <= q2-1; i++)
        {
            a += A[i];
            b += B[i];
            count++;
        }
        vector<ll> difference;
        
        for(ll j = 0; j < a.length(); j++)
        {
            ll compare = b[j] - a[j];
            if(compare >= 0)
            {
                difference.PB(compare);
            }
            else 
            {
                difference.PB(compare+26);
            }
        }

        for(ll j = difference.size()-2; j >= 0; j--)
        {
            difference[j] -= difference[j+1];
            difference[j+1] = 0;

            if(difference[j] < 0)
            {
                difference[j] += 26;
            }
            else if(difference[j] == 0)
            {
                j--;
            }
        }

        ll flag = 0;
        for(ll j = 0; j < count; j++)
        {
            if(difference[i] != 0)
            {
                flag++;
            }
        }

        if(flag)
        {
            cout << "NO" << "\n";
        }
        else
        {
            cout << "YES" << "\n";
        }
    }
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