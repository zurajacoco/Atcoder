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

int n, k;
vector<P> e;
vector<int> edge[2000];
bool visit[2000];
int num;

void dfs(int s, int node) {
    visit[s] = true;
    if (node > k / 2) num++;
    rep(i, edge[s].size()) {
        if (visit[edge[s][i]]) continue;
        dfs(edge[s][i], node + 1);
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin >> n >> k;

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e.pb(P(a, b));
        edge[a].pb(b), edge[b].pb(a);
    }

    int mini = INF;
    if (k % 2 == 0) {
        rep(i, n) {
            rep(j, n) visit[j] = false;
            num = 0;
            dfs(i, 0);
            minch(mini, num);
        }
    } else {
        rep(i, e.size()) {
            rep(j, n) visit[j] = false;
            num = 0;
            visit[e[i].se] = true;
            dfs(e[i].fi, 0);
            dfs(e[i].se, 0);
            minch(mini, num);
        }
    }

    cout << mini << endl;
    return 0;
}