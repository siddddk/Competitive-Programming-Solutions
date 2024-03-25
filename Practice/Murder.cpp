#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

ll merge(ll leftArr[], ll sizeLeft, ll rightArr[], ll sizeRight)
{
    ll ans = 0;
    ll start1 = 0, start2 = 0, start3 = 0;
    ll answer[sizeLeft + sizeRight];
    
    while(start1 < sizeLeft && start2 < sizeRight) {
        if(leftArr[start1] < rightArr[start2]) {
            ans += leftArr[start1]*(sizeRight - start2);
            answer[start3++] = leftArr[start1++];
        }
        else {
            answer[start3++] = rightArr[start2++];
        }
    }

    while(start1 < sizeLeft) answer[start3++] = leftArr[start1++];
    
    while(start2 < sizeRight) answer[start3++] = rightArr[start2++];
    
    for(ll i = 0; i < sizeLeft + sizeRight; i++) leftArr[i] = answer[i];
    
    return ans;
}

long long rec(long long * arr , ll size) {
    if(size <= 1) {
        return 0;
    }
    ll answer = 0;
    ll mid = size / 2;
    answer += rec(arr, mid);
    answer += rec(arr + mid, size - mid);
    sort(arr, arr + mid);
    sort(arr + mid, arr + size);
    answer += merge(arr, mid, arr + mid, size - mid);
    return answer;    
}

void solve(void)
{
    ll n;
    cin >> n;
    ll * nums = new ll[n];
    for(ll i = 0; i < n; i++) cin >> nums[i];
    ll ans = rec(nums, n);
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