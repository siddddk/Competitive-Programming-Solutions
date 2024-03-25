#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef long long ll;
using namespace std;


void solve(void)
{
    string s;
    int n, x;
    cin >> n >> x >> s;
    vector<int> contOnes;
    int counter = 0;
    int noOfOnes = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            counter++;
        }
        else {
            contOnes.PB(counter);
            counter = 0;
        }

        if(s[i] == '1') noOfOnes++;
    }
    contOnes.PB(counter);
    sort(contOnes.begin(), contOnes.end(), greater<int>());
    for(int i = 0; i < contOnes.size(); i++) {
        if(x >= ((2 * contOnes[i]) + 1)) {
            noOfOnes += contOnes[i];
            x -= ((2 * contOnes[i]) + 1);
        }  
        else {
            noOfOnes += ((x - 1) / 2);
            break;
        }      
    }
    cout << noOfOnes << "\n";
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