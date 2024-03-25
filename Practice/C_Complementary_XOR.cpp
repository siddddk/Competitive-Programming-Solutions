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
    string a, b; cin >> a >> b;
    vector<int> s, va, vb;
    int zeroCounter = 0;
    for(int i = 0; i < n; i++) {
        s.PB((a[i] - '0') ^ (b[i] - '0'));
        vb.PB(b[i] - '0');
        va.PB(a[i] - '0');
        if(a[i] - '0' == 0) zeroCounter++;
    }
    
    vector<int> zero (n, 0);
    vector<int> one (n, 1);

    if(va == zero && vb == zero) {
        cout << "YES\n";
        cout << 0 << "\n";
        return;
    }
    else if(va == one && vb == one) {
        cout << "YES\n";
        cout << 2 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << 2 << " " << n << "\n";
        return;
    }


    if(s == zero || s == one) {
        cout << "YES" << "\n";
        if((s == zero && zeroCounter&1) || (s == one && !(zeroCounter&1))) {
            cout << zeroCounter + 1 << "\n";
        }
        else {
            cout << zeroCounter + 2 << "\n";
        }
    }
    else {
        cout << "NO" << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] == '0') {
            cout << i + 1 << " " << i + 1 << "\n";
        }
    }
    
    if((s == zero && zeroCounter&1) || (s == one && !(zeroCounter&1))) {
        cout << 1 << " " << n << "\n";
    }
    else {
        cout << 1 << " " << 1 << "\n";
        cout << 2 << " " << n << "\n";
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