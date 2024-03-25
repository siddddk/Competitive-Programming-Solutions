#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD (int) 1e9 + 7
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


class comparator_class {
public:
    // Comparator function
    bool operator()(vector<ll> o1, vector<ll> o2)
    {
 
        // There can be any condition
        // implemented as per the need
        // of the problem statement
        return (o1.size()
                == o2.size());
    }
};

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
    ll v, e; cin >> v >> e;
    UnionFind parts(v);
    for(int i = 0; i < e; i++) {
        ll a, b; cin >> a >> b;
        a--; b--;
        parts.unionSet(a, b);
    }
    map<ll, vector<ll>> comps;
    for(int i = 0; i < v; i++) {
        comps[parts.findSet(i)].PB(i + 1);
    }
    vector<vector<ll>> ans;
    for(auto x : comps) {
        ans.PB(x.S);
    }
    sort(ans.begin(), ans.end(), comparator_class());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }    
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