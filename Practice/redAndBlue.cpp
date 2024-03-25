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
    string s;
    cin >> s;
    vector<int> d (n, 0);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int lastBlue = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'B') {
            lastBlue = i;
            break;
        }
    }
    int red = 0;
    int moves = 0;
    int maxAhead = d[0];
    int answer = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'B' && i > red) {
            red = maxAhead;
            if(maxAhead >= lastBlue) {
                answer = moves;
                break;
            }
            moves++;
            if(red < i) {
                answer = -1;
                break;
            }
        }
        else {
            maxAhead = max(i + d[i], maxAhead);
        }
    }

    cout << answer << "\n";
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