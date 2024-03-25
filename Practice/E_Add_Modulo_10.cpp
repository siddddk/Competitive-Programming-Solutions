#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

int next(int a) {
    return a + a % 10;
}

void solve(void)
{
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(a[i] % 5 == 0) {
            flag = true;
            a[i] = next(a[i]);
        }
    }
    
    if(flag) {
        if(*max_element(a, a + n) == *min_element(a, a + n)) {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }
    else {
        bool flag2 = false, flag12 = false;
        for(int i = 0; i < n; i++) {
            int x = a[i];
            while(x % 10 != 2) {
                x = next(x);
            }
            if(x % 20 == 12) flag12 = true;
            else flag2 = true;
        }
        if(flag2 && flag12) {
            cout << "No\n";
        } else cout << "Yes\n";
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