#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define vi vector<int>

using namespace std;


int main() {
	int n, x; cin >> n >> x;
	vi a(n);
	map<int, int> vals;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if(vals.count(x - a[i])){
			cout << i + 1 << " " << vals[x - a[i]] << "\n";
			return 0;
		}
		vals[a[i]] = i + 1;
	}
	cout << "IMPOSSIBLE" << '\n';
}