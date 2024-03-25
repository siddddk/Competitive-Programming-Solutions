#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;
vector<bool> chosen;
string S;
vector<char> permutation;

void search(void)
{
    if (permutation.size() == chosen.size()) {
    for(int i = 0; i < chosen.size(); i++)
    {
        cout << permutation[i];
    }
    cout << "\n";
    } else {
    for (int i = 0; i < chosen.size(); i++) {
    if (chosen[i]) continue;
    chosen[i] = true;
    permutation.push_back(S[i]);
    search();
    chosen[i] = false;
    permutation.pop_back();
    }
}

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string A;
    cin >> A;
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    ll n = A.length();
    for(int i = 0; i < n; i++)
    {
        S += A[i];
    }

    for(int i = 0; i < n; i++)
    {
        chosen.PB(false);
    }      
}
