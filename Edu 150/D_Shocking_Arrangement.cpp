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
    int n; cin >> n;
    vector<int> a(n), p; cin >> a;
    if(*max_element(all(a)) == *min_element(all(a))) {
        cout << "NO";
        return;
    }
    
    multiset<int> pos, neg;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) p.push_back(a[i]);
        else if(a[i] < 0) neg.insert(a[i]);
        else if (a[i] > 0) pos.insert(a[i]);
    }

    auto it = pos.begin();
    p.push_back(*it);
    pos.erase(it);
    int sum = p.back();
    while(!pos.empty() || !neg.empty()) {
        if(sum > 0) {
            p.push_back(*neg.begin());
            sum += *neg.begin();
            neg.erase(neg.begin());
        }
        else {
            p.push_back(*pos.begin());
            sum += *pos.begin();
            pos.erase(pos.begin());
        }
    }

    cout << "YES\n";
    cout << p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        solve();
        cout << '\n';
    }
    return 0;
}