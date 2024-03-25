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
    string sClone = s;
    unordered_map<int, int> toSkip;
    sort(sClone.begin(), sClone.end());
    int start = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == sClone[start]) {
            toSkip[s[i] - '0']++;
            start++;
        }
    }
    vector<int> v;
    for(int i = 0; i < s.length(); i++) {
        v.push_back(s[i] - '0');
    }
    string ans = "";
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        if(v[i] != 9) {
            if(toSkip[v[i]] >= 1) {
                toSkip[v[i]]--;
            }
            else v[i]++;
        }
        ans += v[i] + '0';
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