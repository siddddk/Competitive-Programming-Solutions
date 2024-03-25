#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;

bool checker(vector<int> &boxes, int candies, int children)
{
    int noOfChildren = 0;
    for (int i = 0; i < boxes.size(); i++)
    {
        noOfChildren += (boxes[i] / candies);
        if (noOfChildren >= children)
        {
            return true;
        }
    }
    return false;
}

void solve(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> boxes(n, 0);
    for (int i = 0; i < n; i++)
        cin >> boxes[i];

    sort(boxes.begin(), boxes.end(), greater<int>());

    int start = 0;
    int end = boxes[0];
    int mid;
    int ans = 0;
    while (end >= start)
    {
        mid = (start + end) / 2;
        //cout << start << " " << mid << " " << end << "\n";
        if (checker(boxes, mid, k))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}