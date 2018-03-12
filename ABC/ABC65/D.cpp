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
typedef pair<int, P> PIP;

#define INF INT_MAX/3
#define MAX_N 100010

struct union_find {
    int rank[MAX_N], par[MAX_N];
    int cnt = 0;

    union_find(int n) { rep(i, n) rank[i] = 1, par[i] = i; }

    int find(int x) {
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y, int cost) {
        x = find(x); y = find(y);
        if(x == y) return;
        cnt += cost;
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
    int n;
    cin >> n;
    P x[n], y[n];
    rep(i, n) {
        cin >> x[i].fi >> y[i].fi;
        x[i].se = y[i].se = i;
    }
    sort(x, x + n), sort(y, y + n);

    vector<PIP> v;
    rep(i, n - 1) {
        v.pb(PIP(x[i + 1].fi - x[i].fi, P(x[i].se, x[i + 1].se)));
        v.pb(PIP(y[i + 1].fi - y[i].fi, P(y[i].se, y[i + 1].se)));
    }
    sort(v.begin(), v.end());

    union_find uf(n);
    rep(i, v.size()) uf.unite(v[i].se.fi, v[i].se.se, v[i].fi);
    cout << uf.cnt << endl;
    return 0;
}