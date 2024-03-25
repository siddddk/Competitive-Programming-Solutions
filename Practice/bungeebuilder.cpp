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
    vector<int> h (n, 0);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int maxH = h[0];
    int minH = h[0];
    int ansF = 0;
    for(int i = 1; i < n; i++) {
        if(h[i] >= maxH) {
            ansF = max(ansF, maxH - minH);
            minH = h[i];
            maxH = h[i];
        }
        else {
            minH = min(minH, h[i]);
            maxH = max(maxH, h[i]);
        }
    }
    reverse(h.begin(), h.end());
    maxH = h[0];
    minH = h[0];
    int ansB = 0;
    for(int i = 1; i < n; i++) {
        if(h[i] > maxH) {
            ansB = max(ansB, maxH - minH);
            minH = h[i];
            maxH = h[i];
        }
        else {
            minH = min(minH, h[i]);
            maxH = max(maxH, h[i]);
        }
    }
    cout << max(ansF, ansB);
    

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}