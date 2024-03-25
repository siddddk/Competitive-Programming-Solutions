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
    vector<int> a (n, 0);
    for(int i = 0; i < n; i++) cin >> a[i];
    int freq = 0;
    for(int i = n; i >= 1; i--) {
        freq += min(min(i, abs(n - i + 1)), ((n - 1) / 2)  + 1);    
    }
    freq--;
    unordered_map<int, int> umap;
    int num = 1;
    for(int i = ((n - 1) / 2) + 1; i >= 1; i--) {
        umap[i] = freq;
        if(n&1) {
            freq -= 2*num - 1;
        }
        else {
            freq -= 2*num;
        }
        num++;
    }
    int x = 0;
    for(int i = n; i >= 1; i--) {
        int numFreq = umap[min(min(i, abs(n - i + 1)), ((n - 1) / 2)  + 1)];
        cout << a[i - 1] << " " << numFreq << "\n";
        if(numFreq&1) {
            x ^= a[i - 1];
        }
    }
    cout << x << "\n";

    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}