#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

const int MAXN = 1e7 + 1;
bool v[MAXN];
int len, sp[MAXN]; //sp is the smallest prime factor of i
void Sieve(){
    sp[0] = sp[1] = 1;
    for (int i = 2; i < MAXN; i += 2) sp[i] = 2;//even numbers have smallest prime factor 2
    for (long long i = 3; i < MAXN; i += 2) {
        if (v[i]) continue;
        sp[i] = i;
        for (long long j = i; (j*i) < MAXN; j += 2){
            if (!v[j*i]) {
                v[j*i] = true;
                sp[j*i] = i;
            }
        }
    }
} 
void getPrimeFactorization(int n, vector<int> &primes){
    while(n != 1){
        primes.push_back(sp[n]);
        int x = sp[n];
        while(n != 1 && n % x == 0) n /= x;
    }
}
ll modmul(ll a, ll b, ll M) {
    ll ret = a * b - M * ll(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ll modpow(ll b, ll e, ll mod) {
    ll ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
} 
bool isPrime(ll n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ll A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n >> s;
    for (ll a : A) {   // ^ count trailing zeroes
        ll p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
} 
ll pollard(ll n) {
    auto f = [n](ll x) { return modmul(x, x, n) + 1; };
    ll x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
vector<ll> factor(ll n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ll x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

void solve(void) 
{
    int n, m; cin >> n >> m;
    bool flag = true;
    vector<ll> f = factor(n);
    for(auto x : f) {
        if(x >= 2 && x <= m) {
            flag = false;
        }
    }
    if(flag) {
        cout << "YES\n";
    }
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}