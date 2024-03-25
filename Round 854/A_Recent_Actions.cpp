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
    vector<int> p(m); cin >> p;
    set<int> s;
    map<int, int> rem;
    queue<int> q;
    for(int i = n; i >= 1; i--) {
        s.insert(i);
        q.push(i);        
    }
    for(int i = 0; i < m; i++) {
        auto it = s.find(p[i]);
        if(it == s.end()) {
            auto it2 = s.find(q.front());
            s.erase(it2);
            rem[q.front()] = i + 1;
            q.pop();
            q.push(p[i]);   
            s.insert(p[i]);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(rem.count(i)) {
            cout << rem[i] << " ";
        }
        else cout << -1 << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}