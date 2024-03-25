#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n;
    cin >> n;
    set<int> s;
    int start = 1;
    int last = 0;
    for(int i = 1; i <= n; i++) s.insert(i);
    while(!s.empty()) {
        vector<int> r;
        for(auto x : s) {
            r.PB(x);
        }
        if(r.size() == 1) {
            last = r[0];
            break;
        }
        unsigned int i;
        for(i = start;i < r.size(); i+=2) {
            cout << r[i] << " ";
            s.erase(r[i]);
        }
        if(i == r.size()) start = 0;
        else start = 1;
    }
    if(last) cout << last << " ";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}