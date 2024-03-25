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
    int a[n], b[n];
    int sumA = 0, sumB = 0;
    string A = "";
    string B = "";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sumA += a[i];
        if(a[i]) A += "1";
        else A += "0"; 
    }
    int diff = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sumB += b[i];
        if(b[i]) B += "1";
        else B += "0";
    }
    diff = abs(sumA - sumB);
    if(diff == 0) {
        if(A == B) {
            cout << 0 << "\n";
        } 
        else cout << 1 << "\n";
        return;
    }
    else {
        int ans = diff;
        int counter = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i] && a[i] == 1) {
                counter++;
            }
        }
        if(counter == min(sumA, sumB)) {
            cout << ans << "\n";
        }
        else {
            cout << ans + 1 << "\n";
        }
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