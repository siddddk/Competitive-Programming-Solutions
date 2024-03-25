#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

int main()
{
    string input;
    cin >> input;
    ll n = input.length();
    
    ll longestRepetition = 1;
    ll count = 1;
    for(int i = 1; i < n; i++)
    {
        if(input[i] == input[i - 1])
        {
            count++;
            if(count > longestRepetition)
            {
                longestRepetition = count;
            }
        }
        else
        {
            count = 1;
        }
    }
    
    cout << longestRepetition;
}