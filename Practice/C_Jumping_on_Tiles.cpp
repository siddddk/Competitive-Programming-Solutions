#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    string s;
    cin >> s;
    vector<pair<char, int>> v; 
    for(int i = 0; i < s.length(); i++) {
        v.push_back(make_pair(s[i], i));
    }
    sort(v.begin(), v.end());
    int firstIndex;
    int lastIndex;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].second == s.size() - 1) {
            lastIndex = i;
        }
        if(v[i].second == 0) {
            firstIndex = i;
        }
    }
    int cost = 0;
    vector<int> path;
    path.PB(1);
    if(firstIndex <= lastIndex) {
        for(int i = firstIndex + 1; i <= lastIndex; i++) {
            cost += abs(v[i].first - v[i - 1].first);
            path.PB(v[i].second + 1);
        }
    }
    else if(firstIndex > lastIndex) {
        for(int i = 0; i < v.size(); i++) { 
            if(i != firstIndex && v[i].first == s[0]) {
                path.push_back(v[i].second + 1);
            }
        }
        for(int i = firstIndex - 1; i >= lastIndex; i--) {
            cost += abs(v[i + 1].first - v[i].first);
            path.PB(v[i].second + 1);
        }
        path.pop_back();
        for(int i = 0; i < v.size(); i++) {
            if(i != lastIndex && v[i].first == s[s.length() - 1]) {
                path.push_back(v[i].second + 1);
            }
        }
        path.push_back(s.length());
    }

    cout << cost << " " << path.size() << "\n";
    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
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