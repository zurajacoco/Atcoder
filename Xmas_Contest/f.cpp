#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,a,b) for(int i=(int)(a-1);i>=b;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define INF INT_MAX/3
#define MAX_N 5

struct union_find {
    int rank[MAX_N], par[MAX_N];

    union_find(int n) { rep(i, n) rank[i] = 1, par[i] = i; }

    int find(int x) {
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        if(rank[x] > rank[y]) par[y] = x;
        else {
            par[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
    bool same(int x, int y) {
        x = find(x); y = find(y);
        return x == y;
    }
};

int main(){
    cin.sync_with_stdio(false);
    P edge[8];
    rep(i, 8) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[i] = P(a, b);
    }
    vector<int> v(8);
    iota(all(v), 0);
    int ans = 0;
    do {
        union_find uf1(5);
        union_find uf2(5);
        bool ok = true;
        rep(i, 4) {
            uf1.unite(edge[v[i]].fi, edge[v[i]].se);
        }
        rep(i, 5) if (!uf1.same(uf1.par[0], uf1.par[i])) ok = false;
        if (!ok) continue;
        ok = true;
        repl(i, 4, 8) {
            uf2.unite(edge[v[i]].fi, edge[v[i]].se);
        }
        rep(i, 5) if (!uf2.same(uf2.par[0], uf2.par[i])) ok = false;
        if (!ok) continue;
        ans++;
    } while(next_permutation(all(v)));
    cout << ans / (24 * 24) << endl;
    return 0;
}