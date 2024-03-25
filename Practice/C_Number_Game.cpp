#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n; cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }
    for(int k = n; k >= 1; k--) {
        multiset<int> sClone = s;
        for(int i = 1; i <= k; i++) {
            auto it = sClone.upper_bound(k - i + 1);
            if(it == sClone.begin()) break;
            sClone.erase(--it);
            if(!sClone.empty()) {
                int temp = *sClone.begin();
                sClone.erase(sClone.begin());
                sClone.insert(temp + k - i + 1);
            }
            if(i == k) {
                cout << k << "\n";
                return;
            }
        }
        // cout << "Not working for k = " << k << "\n";
    }
    cout << 0 << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}

