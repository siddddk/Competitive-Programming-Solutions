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

pair<bool, int> ok(vector<int> a, vector<int>& b, vector<int>& c, int x) {
    int n = a.size();

    map<int, int> m;
    for(int i = 0; i < n; i++) {
        if(a[i] > max(x, b[i])) {
            m[c[i]] += (a[i] - max(x, b[i]));
        }
    }

    vector<pair<int, int>> cost;
    for(auto x : m) {
        cost.push_back({x.first, x.second});
    }
    
    int start = 0, totalCost = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < x) {
            while(a[i] < x) {
                if(start < cost.size()) {
                    int tmp = min(cost[start].second, x - a[i]); 
                    cost[start].second -= tmp;
                    totalCost += tmp * cost[start].first;
                    a[i] += tmp;
                    if(cost[start].second == 0) start++;
                }
                else return {false, INT_MAX};
            }
        }
    }

    return {true, totalCost};
}

void solve(void) 
{
    int n; cin >> n;
    vector<int> a(n), b(n), c(n); cin >> a >> b >> c;

    int l = *min_element(a.begin(), a.end()), r = *max_element(a.begin(), a.end());

    while(r - l > 1) {
        int m = (l + r) >> 1;
        pair<bool, int> ans = ok(a, b, c, m);
        if(ans.first) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }

    pair<bool, int> ans1 = ok(a, b, c, l), ans2 = ok(a, b, c, r);
    if(ans1.first) {
        cout << ans1.second << '\n';
    }
    else cout << ans2.second << '\n';        
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}