#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n, k;
    string S;
    cin >> n >> k >> S;
    string ans = "";
    ll start = 0;
    ll end = k-1;

    while(start < end)
    {
        ans += S[start];
        ans += S[end];
        start++;
        end--;
    }
    if(start == end) ans += S[start];

    reverse(ans.begin(), ans.end());
    ans += S.substr(k, n);

    cout << ans << "\n";

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