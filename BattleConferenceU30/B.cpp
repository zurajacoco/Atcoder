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

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(){
  cin.sync_with_stdio(false);
  int panel[13][13] = {};

  rep(i, 9) {
    string s;
    cin >> s;
    rep(j, 9) {
      panel[i + 2][j + 2] = s[j] - '0';
    }
  }

  bool ok[3];
  rep(i, 9) {
    ok[0] = true;
    int row[10] = {};
    rep(j, 9) {
      row[panel[i + 2][j + 2]]++;
      if (row[panel[i + 2][j + 2]] > 1) {
        ok[0] = false;
        break;
      }
    }
    if(!ok[0]) break;
  }

  rep(i, 9) {
    ok[1] = true;
    int col[10] = {};
    rep(j, 9) {
      col[panel[j + 2][i + 2]]++;
      if (col[panel[j + 2][i + 2]] > 1) {
        ok[1] = false;
        break;
      }
    }
    if(!ok[1]) break;
  }

  ok[2] = true;
  rep(i, 9) {
    rep(j, 9) {
      rep(k, 8) {
        if (panel[i + 2][j + 2] == panel[i + 2 + dy[k]][j + 2 + dx[k]]) {
          ok[2] = false;
          break;
        }
      }
      if(!ok[2]) break;
    }
    if (!ok[2]) break;
  }

  if (ok[0] && ok[1] && ok[2]) {
    print("Yes");
  } else {
    print("No");
  }

  return 0;
}