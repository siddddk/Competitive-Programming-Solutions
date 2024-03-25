#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
 
 
void solve(void)
{
    int n, k;
    cin >> n >> k;
    set<int> s;
    for(int i = 0; i < n; i++) s.insert(i);
    vector<int> r;
    int start = k;
    while(!s.empty()) {
        for(auto x : s) {
            r.PB(x);
        }
        if(r.size() == 1) {
            break;
        }
        int i;
        for(i = start; i < r.size(); i += k + 1) {
            cout << r[i] + 1 << " ";
            s.erase(r[i]);
        }
        start = i;
        start %= n;
        cout << "\n start: " << start << "\n";
        r.clear();
    }   
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}