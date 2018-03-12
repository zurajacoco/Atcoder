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
#define MAX_N 2005

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int panel[MAX_N][MAX_N] = {};
int n, k, q;

void dfs(int i, int j, int p) {
  panel[i][j] = p;
  rep(k, 4) {
    if (0 < i + dy[k] && i + dy[k] < n + 1 && 0 < j + dx[k] && j + dx[k] < n + 1 && panel[i + dy[k]][j + dx[k]] == 0)
      dfs(i + dy[k], j + dx[k], p);
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n >> k >> q;

  rep(i, n + 1) {
    string s = "";
    if (i > 0) {
      cin >> s;
    }
    rep(j, n + 1) {
      if (j == 0 || i == 0 || s[j - 1] == '#') {
        panel[i][j]++; panel[i + k][j + k]++;
        panel[i + k][j]--; panel[i][j + k]--;
      }
    }
  }

  repl(i, 1, n + 1) {
    rep(j, n + 1) {
      panel[i][j] += panel[i - 1][j];
    }
  }

  rep(i, n + 1) {
    repl(j, 1, n + 1) {
      panel[i][j] += panel[i][j - 1];
    }
  }

  int p = -1;
  repl(i, 1, n + 1) {
    repl(j, 1, n + 1) {
      if (panel[i][j] == 0) dfs(i, j, p--);
    }
  }

  k--;
  rep(i, q) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (panel[r1 + k][c1 + k] < 0 && panel[r2 + k][c2 + k] < 0 && panel[r1 + k][c1 + k] == panel[r2 + k][c2 + k]) {
      print("Yes");
    } else {
      print("No");
    }
  }

  return 0;
}