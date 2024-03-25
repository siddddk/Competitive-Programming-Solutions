#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int x, n; cin >> x >> n;
    set<int> lights;
    multiset<int> lengths;
    lights.insert(0); lights.insert(x);
    lengths.insert(x);
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        auto it = lights.upper_bound(a);
        auto prev = --it;
        ++it;
        lengths.erase(lengths.find(abs(*(it) - *(prev))));
        lengths.insert(abs(a - *(it)));
        lengths.insert(abs(a - *(prev)));
        //cout << abs(*(it) - *(prev)) << " erased " <<  abs(a - *(it)) << " and " << abs(a - *(prev)) << " inserted\n";
        lights.insert(a);
        cout << *(--lengths.end()) << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}