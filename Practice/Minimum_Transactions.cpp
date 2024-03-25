#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (ll) 1e9 + 7
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

class UnionFind {     
                            
private:
    vector<ll> p, rank, setSize;                           
    ll numSets;

public:
    UnionFind(ll N) {
        p.assign(N, 0); 
        for (ll i = 0; i < N; ++i){
            p[i] = i;
        }
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional speedup
        numSets = N;                                 // optional speedup
    }

    ll findSet(ll i) {
        ll root = i;
        while(root != p[root]){
            root = p[root];
        }

        while(i != root){
            ll next = p[i];            // william fiset non recursive implementation
            p[i] = root;
            i = next;
        }

        return root;
    
    }
    bool isSameSet(ll i, ll j) { 
        return findSet(i) == findSet(j); 
    }

    ll numDisjointSets() { 
        return numSets;
    }     
    ll sizeOfSet(ll i) { 
        return setSize[findSet(i)];
    } 

    void unionSet(ll i, ll j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        ll x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }
};

void solve(void) 
{  
    ll start = 0;
    ll n, m; cin >> n >> m;
    UnionFind club(n);
    for(ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        --u; --v;
        club.unionSet(u, v);
    }
    ll totalCoins = 0;
    map<ll, ll> clubCoins;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        totalCoins += x;
        clubCoins[club.findSet(i)] += x;
    }
    ll clubSize = club.numDisjointSets();
    ll ideal = (totalCoins / clubSize);
    ll remaining  = (totalCoins % clubSize);
    ll transactions = 0;
    ll extraCount = 0;
    for(auto x : clubCoins) {
        if(x.S <= ideal) transactions += (ideal - x.S);
        else if(x.S > ideal) extraCount++;
    }
    if(extraCount < remaining) transactions += (remaining - extraCount);
    cout << transactions << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}