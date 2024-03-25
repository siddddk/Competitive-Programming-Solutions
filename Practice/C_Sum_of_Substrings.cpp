#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
typedef long long ll;
using namespace std;

int calc(string s, int n) {
    int f = 0;
    for(int i = 0; i < n - 1; i++) {
        f += ((s[i] - '0') * 10) + (s[i + 1] - '0');
    }
    return f;
}

void solve(void)
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    // cout << calc(s, n) << "\n";
    if(k == 0) {
        cout << calc(s, n) << "\n";
    } 
    else {
        if(s[n - 1] == '0') {
            int count = 1;
            for(int i = n - 2; i >= 0; i--) {
                if(s[i] == '1') {
                    if(count <= k) {
                        swap(s[i], s[n - 1]);
                        k -= count;
                    }
                    break;
                }
                else count++;
            }
        }
        
        if(s[0] == '0') {
            int count = 1;
            for(int i = 1; i < n; i++) {
                if(s[i] == '1') {
                    if(count <= k) {
                        string sC = s;
                        swap(sC[i], sC[0]);
                        if(calc(sC, n) < calc(s, n)) {
                            swap(s[i], s[0]);
                        }
                    }
                    break;
                }
                else count++;
            }
        }
        cout << calc(s, n) << "\n";
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