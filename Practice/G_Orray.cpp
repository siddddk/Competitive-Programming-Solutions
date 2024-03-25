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
    int * a = new int[n];
    int m = INT_MIN;
    int i1, i2 = 0;
    int o = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        o |= a[i];
    }
    sort(a, a + n, greater<int>());
    vector<bool> vis(n + 1, false);
    int Or = a[0];
    vis[0] = true;
    cout << a[0] << " ";
    for(int i = 0; i < n - 1; i++) {
        int max = Or;
        int maxIndex = i + 1;
        for(int j = i + 1; j < n; j++) {
            int tempOr = Or;
            if(!vis[j]) {
                tempOr = Or | a[j];
                if(tempOr > max) {
                    max = tempOr;
                    maxIndex = j;
                }
            }
        }
        Or |= max;
        cout << a[maxIndex] << " ";
        vis[maxIndex] = true;
        if(Or == o) break;
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) cout << a[i] << " ";
    }
    cout << "\n";
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