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
    cin >> n;
    string s[3][n];
    unordered_map<string, int> umap;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin >> s[i][j];
            umap[s[i][j]]++;
        }
    }
    vector<int> points (3, 0);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            if(umap[s[i][j]] == 1) {
                points[i] += 3;
            }
            else if(umap[s[i][j]] == 2) {
                points[i] += 1;
            }
        }
    }

    for(int i = 0; i < 3; i++) {
        cout << points[i] << " ";
    }

    cout << "\n";
    return;
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