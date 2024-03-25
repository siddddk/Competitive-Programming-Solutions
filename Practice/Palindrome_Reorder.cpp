#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef int ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    ll n = S.length();

    char answer[n];
    for(ll i = 0; i < n; i++)
        answer[i] = 'a';
    ll start = 0;
    ll end = n-1;
    char middleChar;
    ll oddCount = 0;
    for(ll i = 0; i < n; i++)
    {
        if(S[i] == S[i+1])
        {
            answer[start] = S[i];
            answer[end] = S[i];
            start++;
            end--;
            i++;
        }
        else
        {
            middleChar = S[i];
            oddCount++;
        }            
    }
    for(ll i = 0; i < n; i++)
    {
        if(answer[i] == 'a')
        {
            answer[i] = middleChar;
        }
    }

    if(oddCount > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    for(ll i = 0; i < n; i++)
    {
        cout << answer[i];
    }

    return 0;
}