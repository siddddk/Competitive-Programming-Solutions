#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
bool check(int cows, vector<int> & stalls, int n, int distance) {
    int count = 1;
    int last_position = 0;
    for(int i = 1; i < n; i++) {
        if(stalls[i] - stalls[last_position] >= distance) {
            count++;
            last_position = i;
        }

        if(count == cows) return true;
    }
    return false;
}

void solve(void)
{
    int n, c;
    cin >> n >> c;
    vector<int> stall (n, 0);
    for(int i = 0; i < n; i++) {
        cin >> stall[i];
    }
    sort(stall.begin(), stall.end());

    int min = 0;
    int max = stall[n - 1] - stall[0];
    int ans = 0;
    while(min <= max) {
        int mid = (min + max) / 2;
        
        if(check(c, stall, n, mid)) {
            ans = mid;
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }
    cout << ans << "\n";   
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