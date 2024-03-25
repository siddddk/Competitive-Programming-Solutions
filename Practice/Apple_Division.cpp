#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
vector<ll> group1;
vector<ll> group2;
ll sum(vector<ll> group)
{
    ll sum = 0;
    for(ll i = 0; i < group.size(), i++;)
    {
        sum += group[i];
    }
    return sum;
}
void function123(vector<ll> group1, vector<ll> group2)
{
    sort(group1.begin(), group1.end());
    sort(group2.begin(), group2.end());
    cout << sum(group1);

    if(sum(group1) - sum(group2) > group1[0])
    {
        group2.PB(group1[0]);
        group1.erase(group1.begin());
    }
    else
    {
        cout << sum(group1) - sum(group2);
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll p[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        group1.PB(p[i]);
    }

    function123(group1, group2);



    return 0;
}