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
    string ans = "";
    for(int i = n; i >= 0; i--) {
        if(i >= 2 && s[i] == '0') {
            int num = (s[i - 1] - '0') + (10 * (s[i - 2] - '0'));
            char c = num + 'a' - 1;
            ans += c;
            i -= 2;
        }
        else {
            int num = s[i] - '0';
            if(num >= 1 && num <= 26) {
                char c = num + 'a' - 1;
                ans += c;
            }
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}