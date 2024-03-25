#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
using namespace std;

int subArraySumPrint(ll arr[], ll n, ll sum, ll powerOf2)
{
    /* Initialize curr_sum as value of
    first element and starting point as 0 */
    ll curr_sum = arr[0], start = 0, i;

    /* Add elements one by one to curr_sum and
    if the curr_sum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++) {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        // If curr_sum becomes equal to sum,
        // then return true
        if (curr_sum == sum && start != i - 1) {
            cout << i - start << " " << powerOf2 << "\n";
            for(int k = start + 1; k < i + 1; k++)
            {
                cout << k << " ";
            }
            cout << '\n';
            return 1;
        }

        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }

    // If we reach here, then no subarray
    cout << "No subarray found";
    return 0;
}


int subArraySum(ll arr[], ll n, ll sum)
{
    /* Initialize curr_sum as value of
    first element and starting point as 0 */
    ll curr_sum = arr[0], start = 0, i;

    /* Add elements one by one to curr_sum and
    if the curr_sum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++) {
        // If curr_sum exceeds the sum,
        // then remove the starting elements
        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        // If curr_sum becomes equal to sum,
        // then return true
        if (curr_sum == sum && start != i - 1) {
            return 1;
        }

        // Add this element to curr_sum
        if (i < n)
            curr_sum = curr_sum + arr[i];
    }

    // If we reach here, then no subarray
    return 0;
}

ll highestPowerof2(ll n)
{
    ll res = 0;
    for (ll i=n; i>=1; i--)
    {
        // If i is a power of 2
        if ((i & (i-1)) == 0)
        {
            res = i;
            break;
        }
    }
    return res;
}

bool isPowerofTwo(ll n)
{
    if (n == 0)
        return 0;
    if ((n & (~(n - 1))) == n)
        return 1;
    return 0;
}

void solve(void)
{
    ll N;
    cin >> N;
    ll A[N];
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    ll sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += A[i];
    }

    if(isPowerofTwo(sum))
    {
        cout << 0 << "\n";
    }
    else
    {
        ll difference = sum - highestPowerof2(sum);
        cout << difference << "\n";

        for(int j = 1; j <= 30; j++)
        {
                for(int i = 0; i < N; i++)
                {
                    A[i] *= (pow(2, j) - 1);
                }
                cout << "\n";
                if(subArraySum(A, N, difference))
                {
                    cout << j << "\n";
                    subArraySumPrint(A, N, difference, pow(2, j));
                    return;
                }

        }
    }
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
