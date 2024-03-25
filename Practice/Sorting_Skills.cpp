#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

bool checksort(vector<int> arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            if(arr[i] - arr[i + 1] == 1) {
                swap(arr[i], arr[i + 1]);
            }
            else return false;
        }
        for(int j = 0; j < n; j++) {
            cout << arr[j] << " ";
        }
        cout << "\n";
    }
    return true;
}

void solve(void)
{
    int n;
    cin >> n;
    vector<int> skills(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> skills[i];
    }
    if(checksort(skills, n)) cout << "YES" << "\n";
    else cout << "NO" << "\n";

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