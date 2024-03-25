#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void solve(void)
{
    ll n, m; cin >> n >> m;
    --m;
    vector<ll> a(n, 0), prefix(n, 0); cin >> a;
    prefix[0] = a[0];
    for(ll i = 1; i < n; i++) prefix[i] = prefix[i - 1] + a[i];
    ll ops = 0;
    vector<ll> pClone = prefix;
    priority_queue<ll, vector<ll>, greater<ll>> pq1; ll carry = 0;
    for(ll i = m + 1; i < n; i++) {
        pq1.push(a[i]);
        while(!pq1.empty() && pClone[i] - 2*carry < pClone[m]) {
            carry += pq1.top();
            ops++;
            pq1.pop();
        }
    } 
    priority_queue<ll> pq2;
    for(ll i = m; i >= 0; i--) {
        while(!pq2.empty() && prefix[i] < prefix[m]) {
            prefix[m] -= 2*pq2.top();
            ops++;
            pq2.pop();
        }
        pq2.push(a[i]);
    }
    cout << ops << "\n";
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