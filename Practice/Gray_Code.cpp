#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

vector<string> grayCode(ll n)
{
    if(n <= 0) return {"0"};

    if(n == 1) return {"0", "1"};

    vector<string> prevAnswer = grayCode(n-1);

    vector<string> ans;

    for(ll i = 0; i < prevAnswer.size(); i++)
    {
        string s = prevAnswer[i];
        ans.PB("0" + s);
    }

    for(ll i = prevAnswer.size() - 1; i >= 0; i--)
    {
        string s = prevAnswer[i];
        ans.PB("1" + s);
    }

    return ans;
}

void printAns(ll n)
{
    vector<string> mainAns;
    mainAns = grayCode(n);

    for(ll i = 0; i < mainAns.size(); i++)
    {
        cout << mainAns[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    printAns(n);    
    return 0;
}