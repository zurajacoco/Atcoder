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


int main(){
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  int c[n][n], home[n];
  rep(i, n)rep(j, n) c[i][j] = INF;
  rep(i, n) home[i] = INF;

  rep(i, m) {
    int u, v, l;
    cin >> u >> v >> l;
    u--; v--;
    if (u != 0) c[u][v] = c[v][u] = l;
    else home[v] = l;
  }

  rep(i, n)rep(j, n)rep(k, n) minch(c[j][k], c[j][i] + c[i][k]);

  int ans = INF;
  repl(i, 1, n)repl(j, i + 1, n) {
    minch(ans, home[i] + home[j] + c[i][j]);
  }

  print(((ans != INF) ? ans : -1));

  return 0;
}