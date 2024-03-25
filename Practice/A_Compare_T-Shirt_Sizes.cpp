#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

int getScore(string s) {
    int sScore = 0;
    if(s[s.length() - 1] == 'L') {
        sScore += 100;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'X') {
                sScore++;
            }
        }
        return sScore;
    }   
    else if(s[s.length() - 1] == 'S') {
        sScore = -1;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'X') sScore--;
        }
        return sScore;
    }
    else {
        return 0;
    }
}

void solve(void)
{
    string a, b; cin >> a >> b;
    if(getScore(a) > getScore(b)) {
        cout << ">" << "\n";
    }
    else if(getScore(a) < getScore(b)) {
        cout << "<" << "\n";
    }
    else {
        cout << "=" << "\n";
    }
    return;     
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