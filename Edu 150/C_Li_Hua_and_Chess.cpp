#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
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

void solve(void) 
{
    int n, m; cin >> n >> m;
    int dist1, dist2;
    set<pair<int, int>> s1;
    set<pair<int, int>> s2;
    cout << "? " << 1 << ' ' << 1 << endl;
    cin >> dist1;
    cout << "? " <<  n << ' ' << m << endl;
    cin >> dist2;
    if(dist1 == 0) {
        cout << "! " << 1 << ' ' << 1 << endl;
        return;
    }
    else if(dist2 == 0) {
        cout << "! " << n << ' ' << m << endl;
        return;
    }
    for(int i = 1; i <= 1 + dist1; i++) {
        s1.insert({i, 1 + dist1});
        s1.insert({1 + dist1, i});
    }
    for(int i = m; i >= m - dist2; i--) {
        s2.insert({n - dist2, i});
    }
    for(int i = n; i >= n - dist2; i--) {
        s2.insert({i, m - dist2});
    }
    vector<pair<int, int>> v;        
    for(auto x : s1) {
        if(s2.find(x) != s2.end()) v.push_back(x);
    }
    if(v[0].F <= n && v[0].S <= m && v[0].F >= 1 && v[0].S >= 1) {
        cout << "? " << v[0].F << ' ' << v[0].S << endl; 
        int dist3; cin >> dist3;
        if(dist3 == 0) {
            cout << "! " << v[0].F << ' ' << v[0].S << endl;
        }
        else {
            cout << "! " << v[1].F << ' ' << v[1].S << endl;
        }
    }
    else {
        cout << "! " << v[1].F << ' ' << v[1].S << endl;
    }
    

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        solve();
        cout << endl;
    }
    return 0;
}