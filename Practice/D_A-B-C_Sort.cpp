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
    int a[n];
    vector<int> aClone;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        aClone.PB(a[i]);
    }
    sort(aClone.begin(), aClone.end());
    bool flag = true;
    if(n&1) {
        if(a[0] == aClone[0]) {
            for(int i = 1; i < n - 1; i+=2) {
                if(!((a[i] == aClone[i] && a[i + 1] == aClone[i + 1]) || (a[i] == aClone[i + 1] && a[i + 1] == aClone[i]))) {
                    flag = false;
                }
            }
        }
        else flag = false;
    }
    else {
        for(int i = 0; i < n - 1; i+=2) {
            if(!((a[i] == aClone[i] && a[i + 1] == aClone[i + 1]) || (a[i] == aClone[i + 1] && a[i + 1] == aClone[i]))) {
                flag = false;
            }
        }
    }
    if(flag) cout << "YES" << "\n";
    else cout << "NO" << "\n";
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