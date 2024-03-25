#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int counter = 1;
    vector<char> brackets;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            brackets.PB(s[i]);
        }
        else {
            if(brackets.size() >= 1) {
                counter++;
            }
            brackets.pop_back();
        }
    }

    cout << counter << "\n";
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