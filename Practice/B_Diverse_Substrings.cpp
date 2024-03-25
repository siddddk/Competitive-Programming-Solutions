#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    ll n; cin >> n;
    string s; cin >> s;
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        map<char, ll> m;
        priority_queue<ll> pq;
        for(ll j = i; j < n; j++) {
            m[s[j]]++;
            pq.push(m[s[j]]);
            if(pq.top() <= m.size()) {
                ans++;
            }
            else if(pq.top() > 10) {
                break;
            }
            // cout << s.substr(i, j - i + 1) << " " << " max freq " << pq.top() << " size " << m.size() << " ";
            // (pq.top() <= m.size()) ? cout << "Diverse" : cout << "Not Diverse";
            // cout << "\n";
        }
    }
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