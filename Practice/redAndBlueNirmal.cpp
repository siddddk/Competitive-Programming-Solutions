#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
    }
    int i = 1;
    int max_fill = 1;
    int moves = 1;
    int red = 0;
    while (i <= n)
    {
        if (s[i - 1] == 'R' || i <= red)
        {
            max_fill = max(max_fill, max(i + d[i], i + 1));
        }
        else
        {
            if (max_fill < i)
                return -1;
            else
            {
                moves++;
                red = max_fill;
            }
        }
        ++i;
    }
    return moves;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << '\n';
    }
    return 0;
}