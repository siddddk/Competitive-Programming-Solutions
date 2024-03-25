#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> right(n, 0);
    vector<ll> left(n, 0);
    vector<ll> maxVal(n, 0);

    ll answer = 0;

    for(ll i = 0; i < n; i++) {
        right[i] = n - i - 1;
        left[i] = i;
        ll ans = 0;
        if(n - i - 1 > i) {
            ans = n - i - 1;
        } 
        else ans = i;
        maxVal[i] = ans;
    }
    vector<ll> changes;
    for(ll i = 0; i < n; i++) {
        if(s[i] == 'L') {
            changes.push_back(maxVal[i] - left[i]);
            answer += left[i];
        }
        else {
            changes.push_back(maxVal[i] - right[i]);
            answer += right[i];
        }
    }
    sort(changes.begin(), changes.end(), greater<>());
    vector<ll> toAdd (n + 1, 0);
    for(ll i = 1; i <= n; i++) {
        toAdd[i] = toAdd[i - 1];
        if(i - 1 < changes.size()) {
            toAdd[i] += changes[i - 1];
        }
    }

    for(ll i = 0; i < n; i++) {
        cout << answer + toAdd[i + 1] << " ";
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