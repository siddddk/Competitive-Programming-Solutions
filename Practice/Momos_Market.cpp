// #include <bits/stdc++.h>
// #define F first
// #define S second
// #define PB push_back
// #define MP make_pair
// typedef long long ll;
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     ll n, q;
//     cin >> n;
//     ll rate[n];
//     ll x[n];
//     for(ll i = 0; i < n; i++) cin >> rate[i];
//     cin >> q;
//     for(ll i = 0; i < q; i++) cin >> x[i];


//     for(ll i = 1; i < n; i++) {
//         rate[i] += rate[i - 1];
//     }

//     for(ll i = 0; i < q; i++) {
//         ll index = upper_bound(rate, rate + n, x[i]) - rate;
//         ll remaining = x[i];
//         if(index >= 1) remaining -= rate[index - 1];
//         else index = 0;
//         cout << index << " " << remaining << "\n";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

pair<ll, ll> binarySearch(ll arr[], ll n, ll target) {
    ll start = 0;
    ll end = n - 1;
    while(end > start) {
     	ll mid = (start + end) / 2;
        if(arr[mid] <= target) {
            start = mid;
            if(mid == n - 1 || arr[mid + 1] > target) {
                pair<ll, ll> answer = make_pair(mid + 1, target - arr[mid]);
                return answer;
            }
        }
        else {
            end = mid;
        }
    }    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin >> n;
    ll rate[n];
    ll x[q];
    for(ll i = 0; i < n; i++) cin >> rate[i];
    cin >> q;
    for(ll i = 0; i < q; i++) cin >> x[i];


    for(ll i = 1; i < n; i++) {
        rate[i] += rate[i - 1];
    }

    for(ll i = 0; i < q; i++) {
        pair<ll, ll> answer = binarySearch(rate, n, x[i]);
        cout << answer.first << " " << answer.second << "\n";
    }
    return 0;
}