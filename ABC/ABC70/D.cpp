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
typedef pair<ll, ll> P;

#define INF INT_MAX/3


int main(){
    cin.sync_with_stdio(false);
    int n, q, k;
    cin >> n;
    vector<P> edge[n];
    rep(i, n - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge[a].pb(P(c, b)), edge[b].pb(P(c, a));
    }
    cin >> q >> k; k--;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, k));
    bool visited[n] = {};
    ll cost[n] = {};
    while(que.size()) {
        P p = que.top(); que.pop();
        if (visited[p.se]) continue;
        visited[p.se] = true;
        cost[p.se] = p.fi;
        rep(i, edge[p.se].size()) {
            int u = edge[p.se][i].se, c = edge[p.se][i].fi;
            if (!visited[u]) que.push(P(p.fi + c, u));
        }
    }
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        cout << cost[x - 1] + cost[y - 1] << endl;
    }
    return 0;
}