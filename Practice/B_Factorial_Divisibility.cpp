#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    int n, x; cin >> n >> x;
    int a[n];
    vector<int> map (x + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        map[a[i]]++;
    }

    for(int i = 1; i < x; i++) {
        // cout << "Freq for " << i << " " << map[i] << " \n";
        if(map[i] % (i + 1) == 0) {
            map[i + 1] += (map[i] / (i + 1));
            // cout << (map[i] / (i + 1)) << " added to " << i + 1 << " freq\n";
            map[i] = 0;
        }
        else {
            cout << "No\n";
            return;
        }
    }
    // cout << map[x] << " ";
    if(map[x] != 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}