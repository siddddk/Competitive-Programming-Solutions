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
    int x[n], y[n];
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];

    vector<int> surplus;
    for(int i = 0; i < n; i++) {
        surplus.PB(y[i] - x[i]);
    }
    sort(surplus.begin(), surplus.end());

    for(int i = 0; i < n; i++) {
        cout << surplus[i] << " ";
    }
    cout << "\n";

    int groups = 0;
    int start = 0;
    int end = n - 1;
    while(end > start) {
        if(surplus[start] + surplus[end] >= 0) {
            surplus[end] += surplus[start];
            start++;
            end--;
            groups++;
        }
        else {
            start++;
        }
    }
    cout << groups << "\n";
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