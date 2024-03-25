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
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    bool prev = false;
    int temp = 0;
    vector<int> v;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            temp++;
            i++;
            prev = true;
        }
        else {
            if(temp > 0) v.PB(temp);
            temp = 0;
            prev = false;
        }
    }
    v.PB(temp);
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
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