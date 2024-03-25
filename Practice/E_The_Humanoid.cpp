#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n, hC; cin >> n >> hC; 
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    vector<vector<int>> orders = {{2, 2, 3}, {2, 3, 2}, {3, 2, 2}};
    int maxCount = 0;
    for(int k = 0; k < 3; k++) {
        int h = hC;
        int start = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(h > a[i]) {
                h += a[i] / 2;
                count++;
                maxCount = max(maxCount, count);
            }
            else {
                while(start < 3 && h <= a[i]) {
                    h *= orders[k][start++];
                }
                if(h > a[i]) {
                    h += a[i] / 2;
                    count++;
                    maxCount = max(maxCount, count);
                }
                else break;
            }
        }
    }
    cout << maxCount << "\n";
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