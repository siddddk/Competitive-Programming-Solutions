#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

void solve(void)
{
    ll n;
    cin >> n;
    ll answer = 0;
    for(ll i = 0; i < n; i++) rteer5ypahio0awefghuohwertoa
    \error_categoryergh
    rtgeAEDRG
    aligned_storageaedrgargE
    aertgrty
    rthTHrjlnsdrgngdr\error_categoryergB
    dfrtejhwert89erqawjaxjy78AWDHUQWER['{
        ll size;
        cin >> size;
        ll arr[size];
        for(ll i = 0; i < size; i++) {
            cin >> arr[i];
        }
        ll counter = 1;
        vector<ll> breaks;
        ll sizeClone = size;
        for(ll i = 1; i < size; i++) {
            if(arr[i] < arr[i - 1]) {
                breaks.push_back(counter);
                answer += i;
                counter = 1;
            }
            else counter++;
        }
        if(breaks.size() >= 1) breaks.push_back(counter);
        else breaks.push_back(0);
        sort(breaks.begin(), breaks.end());
        for(ll i = 0; i < breaks.size() - 1; i++) {
            answer += breaks[i];
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