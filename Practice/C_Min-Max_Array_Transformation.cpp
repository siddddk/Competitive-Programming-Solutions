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
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    int answerMin[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        cout << b[it - b.begin()] - a[i] << " \n"[i == n - 1];
    }

    for(int i = 0, j = 0; i < n; i++) {
        j = max(i, j);
        while(j + 1 < n && a[j + 1]  <= b[j]) {
            j++;
        }
        cout << b[j] - a[i] << " \n"[i == n - 1];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    return 0;
}