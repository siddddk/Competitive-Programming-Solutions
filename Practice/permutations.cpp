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
    ll answer[n] = {0};
    ll count = ((n - 1)/2);
    if(n <= 4)
    {
        if(n == 1)
        {
            cout << 1;
        }
        else if(n <= 3 && n > 1)
        {
            cout << "NO SOLUTION";
        }
        else if(n == 4)
        {
            cout << "2 4 1 3";
        }
    }
    else if(n % 2 != 0)
    {
        answer[((n+1)/2) - 1] = n;
        ll start = n - 1;
        ll end = 1;
        ll startPosition = 0;
        ll endPosition = n - 1;
        ll counter = 2;
        while(count)
        {
            answer[startPosition] = start;
            answer[endPosition] = end;
            startPosition++;
            endPosition--;
            if(counter % 2 == 0)
            {
                start--;
                end++;
            }
            else
            {
                start++;
                end--;
            }
            swap(start, end);
            counter++;
            count--;
        }
        
        for(int i = 0; i < n; i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    else if(n % 2 == 0)
    {
        answer[n - 1] = n;
        n -= 1;
        answer[((n+1)/2) - 1] = n;
        ll start = n - 1;
        ll end = 1;
        ll startPosition = 0;
        ll endPosition = n - 1;
        ll counter = 2;
        while(count)
        {
            answer[startPosition] = start;
            answer[endPosition] = end;
            startPosition++;
            endPosition--;
            if(counter % 2 == 0)
            {
                start--;
                end++;
            }
            else
            {
                start++;
                end--;
            }
            swap(start, end);
            counter++;
            count--;
        }
        
        for(int i = 0; i < n; i++)
        {
            cout << answer[i] << " ";
        }
        cout << answer[n] << "\n";
        return 0;
    }
    return 0;
}