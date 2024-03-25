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
    vector<int> a (n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> aClone;
    aClone.PB(a[0]);

    for(int i = 1; i < n; i++) {
        if(a[i] != a[i - 1]) aClone.PB(a[i]);
    }

    if(aClone.size() <= 2) {
        cout << "YES" << "\n";
        return;
    }

    // for(int i = 0; i < aClone.size(); i++) {
    //     cout << aClone[i] << " ";
    // }
    // cout << "\n";

    int counter = 0;
    // if(aClone[0] < aClone[1]) counter++;
    // if(aClone[n - 1] < aClone[n - 2]) counter++;
    for(int i = 1; i < aClone.size() - 1; i++) {
        if(aClone[i] > aClone[i - 1] && aClone[i] > aClone[i + 1]) {
            counter++;
        }
    }
    // cout << counter << "\n";
    if(counter == 0) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
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