#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define aint(x) begin(x), end(x)
typedef long long ll;
using namespace std;
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

void solve(void) 
{
    int n; cin >> n;
    vector<int> posP (n + 2, 0), posQ (n + 2, 0);
    vector<int> p(n); 
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        posP[p[i]] = i;
    }
    vector<int> q(n);
    for(int i = 0; i < n; i++) {
        cin >> q[i];
        posQ[q[i]] = i;
    }
    posP[n + 1] = n;
    posQ[n + 1] = -1;

    ll l = min(posP[1], posQ[1]), r = max(posP[1], posQ[1]);

    ll ans = (l * (l - 1) / 2) + l + ((r - l - 1) * (r - l - 2) / 2) + r - l - 1 + ((n - r - 1) * (n - r - 2) / 2) + n - r - 1;

    for(int num = 2; num <= n; num++) {
        ll mnPos = min(posP[num], posQ[num]), mxPos = max(posP[num], posQ[num]);
        if(mnPos > r) {
            ans += (mnPos - r) * (l + 1);
        }
        else if (mxPos < l) {
            ans += (n - r) * (l - mxPos);    
        }       
        else if(l > mnPos && r < mxPos && num <= n) {
            ans += (l - mnPos)*(mxPos - r);  
        }
        l = min(l, mnPos), r = max(r, mxPos);
    }
    ans++;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}