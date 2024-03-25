#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

ll binpow(ll a, ll x) {
    if(x == 0) return 1ll;
    ll tmp = binpow(a, x / 2);
    if(x&1) {
        return (a * ((tmp * tmp) % mod)) % mod;
    }
    else return ((tmp * tmp) % mod); 
}

void solve(void) 
{
    ll n, A, B; cin >> n >> A >> B;
    vector<ll> a(n); cin >> a;
    ll lastElement = a.back();
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(auto x : a) pq.push(x);
    while(pq.top() < lastElement) {
        ll curr = pq.top(); pq.pop();
        pq.push(curr * A);
        B--;
        if(B == 0) {
            while(!pq.empty()) {
                cout << (pq.top() % mod) << ' ';
                pq.pop();
            }
            return;
        }
    }
    pq.pop();
    pq.push(lastElement * A);
    B--;
    if(B == 0) {
        while(!pq.empty()) {
            cout << (pq.top() % mod) << ' ';
            pq.pop();
        }
        return;
    }
    int start = 0;
    while(!pq.empty()) {
        a[start++] = (pq.top() % mod); 
        pq.pop();
    }
    ll cycles = B / n, remaining = B % n;
    if(cycles > 0) {
        for(int i = 0; i < n; i++) {
            pq.push(binpow(a[i], cycles));
        }
    }
    else {
        for(auto x : a) pq.push(x);
    }
    while(!pq.empty()) {
        ll curr = pq.top(); pq.pop();
        cout << curr << ' ' << curr * A << '\n';
        pq.push(curr * A);
        B--;
        if(B == 0) break;
    }

    while(!pq.empty()) {
        cout << (pq.top() % mod) << ' ';
        pq.pop();
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}