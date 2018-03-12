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
typedef pair<double, P> PLP;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001

bool dijkstra(double);

int h, w, t;
int panel[12][12];
PLP start = PLP(0, P(0, 0));
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
  cin.sync_with_stdio(false);
  cin >> h >> w >> t;

  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) {
      if (s[j] == 'S') {
        start = PLP(0, P(i + 1, j + 1));
        panel[i + 1][j + 1] = 1;
      } else if (s[j] == 'G') {
        panel[i + 1][j + 1] = 3;
      } else if (s[j] == '.') {
        panel[i + 1][j + 1] = 1;
      } else {
        panel[i + 1][j + 1] = 2;
      }
    }
  }

  double ok = 1, ng = t;
  rep(i, 100) {
    double mid = (ok + ng) / 2;
    if (dijkstra(mid)) ok = mid;
    else ng = mid;
  }

  print((int)ok);

  return 0;
}

bool dijkstra(double x) {
  priority_queue<PLP, vector<PLP>, greater<PLP>> q;
  q.push(start);

  bool visited[h + 2][w + 2] = {};
  ll cost = t + 1;
  while(!q.empty()) {
    PLP p = q.top(); q.pop();

    if (visited[p.se.fi][p.se.se]) continue;
    visited[p.se.fi][p.se.se] = 1;

    if (panel[p.se.fi][p.se.se] == 3) {
      cost = p.fi;
      break;
    }

    rep(i, 4) {
      if (!visited[p.se.fi  + dy[i]][p.se.se + dx[i]]) {
        if (panel[p.se.fi + dy[i]][p.se.se + dx[i]] == 1 || panel[p.se.fi + dy[i]][p.se.se + dx[i]] == 3) {
          q.push(PLP(p.fi + 1, P(p.se.fi + dy[i], p.se.se + dx[i])));
        } else if (panel[p.se.fi + dy[i]][p.se.se + dx[i]] == 2) {
          q.push(PLP(p.fi + x, P(p.se.fi + dy[i], p.se.se + dx[i])));
        }
      }
    }
  }

  return (cost > t) ? false : true;
}