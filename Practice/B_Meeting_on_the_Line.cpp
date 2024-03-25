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
    vector<int> x(n, 0);
    vector<float> t(n, 0);
    double answer = 0;
    double toDivide = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        answer += x[i];
        toDivide += t[i];
    }
    cout << (answer + toDivide) / n << "\n";
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