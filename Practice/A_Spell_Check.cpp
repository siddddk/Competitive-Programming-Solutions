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
    if(n != 5) {
        cout << "NO" << "\n";
        return;
    }
    string s;
    cin >> s;
    string toCheck = "Timur";
    sort(s.begin(), s.end());
    sort(toCheck.begin(), toCheck.end());
    cout << toCheck << " " << s << "\n";
    if(toCheck == s) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << "\n";
    return;
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