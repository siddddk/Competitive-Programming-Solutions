#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;

long long ask(int a, int b) {
    long long x; //i wanna kms
    cout << "? " << a << ' ' << b << endl;
    cin >> x;
    return x;
}

long long solve() {
    for(int i = 2; i <= 26; i++) {
        long long x = ask(1, i);
        long long y = ask(i, 1);
        if(x == -1) return i - 1;
        if(x != y) return x + y;
    }
    assert(false);
}

int main()
{
    long long ans = solve();
    cout << "! " << ans << endl;
}