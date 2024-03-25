#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
#define all(x) begin(x), end(x)
typedef long long ll;
using namespace std;

#define ts to_string
string ts(char c) { return string(1, c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { 
	string res = "{"; for(int i = 0; i < si(v); ++i) res += char('0' + v[i]);
	res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) {
	string res = ""; for(int i = 0; i < SZ; ++i) res += char('0' + b[i]);
	return res; }
template<class A, class B> string ts(pair<A,B> p);
template<class T> string ts(T v) { // containers with begin(), end()
	bool fst = 1; string res = "{";
	for (const auto& x: v) {
		if (!fst) res += ", ";
		fst = 0; res += ts(x);
	}
	res += "}"; return res;
}
template<class A, class B> string ts(pair<A,B> p) {
	return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
 
// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
void EDBG(string names) { names = names; }
template<class H, class... T> void EDBG(string names, H h, T... t) {
	auto pos = names.find(',');
	auto first_name = names.substr(0, pos);
	auto rest = names.substr(pos + 1);
	while(rest.front() == ' '){
		rest = rest.substr(1);
	}
	cerr << "[" << first_name << "]: [" << ts(h) << "]" << nl;
	EDBG(rest, t...);
}

// DEBUG
#ifdef LOCAL // compile with -DLOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define edbg(...) EDBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#define edbg(...) 0
#endif

void solve(void)
{
    int dp[1 << 4];
    for(int i = 0; i < (1 << 4); i++) dp[i] = INT_MAX;
    dp[0] = 0;
    for(int mask = 0; mask < ((1 << 4) - 1); mask++) {
        int k = __builtin_popcount(mask);
        for(int j = 0; j < 4; j++) {
            if(!(mask&(1 << j))) {
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[k][j]);
            }
        }
    }
    debug(dp);
    cout << dp[(1 << 4) - 1] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}