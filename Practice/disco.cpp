#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    vector<int> v;
    int nc = n;
    while(nc != 0) {
        v.push_back(nc % 10);
        nc /= 10;
    }
    reverse(v.begin(), v.end());
    if(is_sorted(v.begin(), v.end())) {
        return true;
    }
    else return false;
}

void solve(void)
{
    int count = 0;
    for(int i = 0; i <= 99999; i++) {
        if(check(i)) {
            count++;
        }
    }
    cout << count << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}