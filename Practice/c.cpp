#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

int countDigits(int x) {
    return to_string(x).length();
}

void solve(void)
{
    int n;
    cin >> n;
    priority_queue<int> a;
    priority_queue<int> b;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push(x);
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push(x);
    }

    int answer = 0;

    while(!a.empty()) {
        if(a.top() > b.top()) {
            int temp = countDigits(a.top());
            a.pop();
            a.push(temp);
            answer++;
        }
        else if(b.top() > a.top()) {
            int temp = countDigits(b.top());
            b.pop();
            b.push(temp);
            answer++;
        }
        else {
            b.pop();
            a.pop();
        }
    }

    cout << answer << "\n";
    
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