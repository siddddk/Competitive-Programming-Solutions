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
    vector<int> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        k.PB(x);
    }
    multiset<int> s;
    for(int i = 0; i < n; i++) {
        if(s.empty()) {
            s.insert(k[i]);
        }
        else{
            auto it = s.upper_bound(k[i]);
            if(it != s.end()) {
                s.erase(it);
                s.insert(k[i]);
            }
            else {
                s.insert(k[i]);
            }
        }
    }

    cout << s.size() << "\n";

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}