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

struct vertex {
    vector<int> to;
    int branch;
};

int n;
set<int> p;
vector<int> pa;
int visited[100000];
vertex v[100000];

int dfs(int u) {
    visited[u] = true;
    rep(i, v[u].to.size()) {
        if (visited[v[u].to[i]]) continue;
        int tmp = dfs(v[u].to[i]);
        if (!p.count(v[u].to[i])) v[u].branch += tmp;
    }
    return v[u].branch;
}

bool path(int u, int from) {
    if (u == n - 1) {
        p.insert(u);
        pa.pb(u);
        return true;
    }
    bool on = false;
    rep(i, v[u].to.size()) {
        if (v[u].to[i] == from) continue;
        on |= path(v[u].to[i], u);
    }
    if (on) p.insert(u), pa.pb(u);
    return on;
}

int main(){
    cin.sync_with_stdio(false);
    cin >> n;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].to.pb(b);
        v[b].to.pb(a);
        visited[i] = false;
        v[i].branch = 1;
    }
    v[n - 1].branch = 1; visited[n - 1] = false;
    path(0, -1);
    dfs(0);
    reverse(pa.begin(), pa.end());
    int fennec = 0, snuke = 0, m = pa.size() / 2 + pa.size() % 2;
    rep(i, m) fennec += v[pa[i]].branch;
    repl(i, m, pa.size()) snuke += v[pa[i]].branch;
    if (fennec > snuke) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}