#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=0;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define print(x) cout << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<int, P> PIP;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001

vector<int> edge[2*100000];
bool visited[2*100000];
int pass[2*100000];

int main(){
    cin.sync_with_stdio(false);
    ll n, m, s;
    cin >> n >> m >> s;
    s--;
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edge[u].pb(v), edge[v].pb(u);
    }
    rep(i, n) visited[i] = false, pass[i] = INF;

    priority_queue<P> q;
    q.push(P(s, s));
    while(q.size()) {
        P p = q.top(); q.pop();
        if (visited[p.se]) continue;
        visited[p.se] = true;
        pass[p.se] = p.fi;
        rep(i, edge[p.se].size()) {
            if (!visited[edge[p.se][i]]) q.push(P(min(p.fi, p.se), edge[p.se][i]));
        }
    }
    rep(i, n) if (pass[i] >= i) cout << i + 1 << endl;

    return 0;
}