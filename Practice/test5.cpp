/**
 *    author:  jaytau
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;

#define endl "\n"
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define all(x) (x).begin(), (x).end()

#define F first
#define S second
#define pb push_back
#define mp make_pair

#define fo(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define fo1(i, n) for (int (i) = 1; (i) <= (n); (i)++)
#define foll(i, n) for (ll (i) = 0; (i) < (n); (i)++)
#define fo1ll(i, n) for (ll (i) = 1; (i) <= (n); (i)++)

ll modpower(ll x, ll y, ll p){
    ll res = 1;x = x % p;
    while (y > 0){
        if (y & 1)res = (res * x) % p;
        y = y >> 1;x = (x * x) % p;
    }
    return (res + p) % p;
}
ll modinv(ll x, ll p){return modpower(x, p - 2, p);}
ll modmul(ll a,ll b, ll p){return (a%p*b%p)%p;}
ll modadd(ll a,ll b, ll p){return (a%p+b%p)%p;}
ll modsub(ll a,ll b, ll p){return (a%p-b%p+p)%p;}
ll moddiv(ll a,ll b, ll p){return modmul(a,modinv(b, p), p);}
ll factmod(ll n, ll p) {
    vector<ll> f(p);
    f[0] = 1;
    for (ll i = 1; i < p; i++)
        f[i] = f[i-1] * i % p;

    ll res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res;
}

#define fastio()                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0)

#define test() \
	int _;     \
	cin >> _;  \
	while (_--)

#define test1() \
	int t;      \
	t = 1;      \
	while (t--)


void solve() {
	int n;
	cin >> n;
	vi v(n);
	fo(i, n)	cin >> v[i];
	// for(auto i: l)	cout << i << " ";
	// cout << endl;
	int ans = n;
	// int a = 0, b = 1, c = 1;
	for (int a = 0; a < (n-1); a++) {
		int current_ans = 0;
		int b = a + 1, c = a + 1;
        int sum = accumulate(v.begin(), v.begin() + a + 1, 0);
        int current_sum = 0;
		while ((c < n) && (b < n)) {
			current_sum = accumulate(v.begin() + b, v.begin() + c + 1, 0);
			if (sum == current_sum) {
				current_ans = max(max(current_ans, a + 1), c - b + 1);
				b = c;
			} else if (sum > current_sum) {
				c++;
			} else if (sum < current_sum) {
                cout << " break\n";
                break;
			}
            cout << sum << " " << current_sum << " a: " << a << " c: " << c << "\n";
		}
		if (c == n && sum == current_sum)
			ans = min(ans, current_ans);
		// cout << current_ans << endl;
	}
	cout << ans << endl;
}

int main() {
	fastio();
	test() {
		solve();
	}
	return 0;
}