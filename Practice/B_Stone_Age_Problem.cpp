#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n, q; cin >> n >> q;
    vector<int> v(n, 0);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }

    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int i, x; cin >> i >> x;
            sum += x - v[i];
            v[i] = x;
        }
        else {
            int x; cin >> x;
            v.assign(n, 0);
            sum = n * x;
        }
        cout << sum << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}