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
    string t; cin >> t;
    set<char> s; vector<char> toMap;
    for(int i = 0; i < n; i++) {
        if(s.find(t[i]) == s.end()) {
            toMap.PB(t[i]);
            s.insert(t[i]);
        }
    }
    unordered_map<char, char> umap;
    char code = 'a';
    queue<char> q;
    for(int i = 0; i < toMap.size(); i++) {
        if(toMap[i] == code || umap[code] == toMap[i]) {
            q.push(code);
            if(code != 'z') {
                umap[toMap[i]] = ++code;
            }
            else {
                umap[toMap[i]] = q.front();
                q.pop();
            }
        }
        else {
            if(!q.empty()) {
                umap[toMap[i]] = q.front();
                q.pop();
            }
            else {
                umap[toMap[i]] = code++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << umap[t[i]];
    }
    cout << "\n";
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