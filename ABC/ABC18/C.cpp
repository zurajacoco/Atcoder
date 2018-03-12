#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=1;i--)
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
  int r, c, k;
  cin >> r >> c >> k;

  int cells[r + 2][c][3] = {};
  repl(i, 1, r + 1) {
    string s;
    cin >> s;
    rep(j, c) {
      if (s[j] == 'x') {
        cells[i][j][0] = cells[i][j][1] = 0;
      } else {
        cells[i][j][0] = 1;
        cells[i][j][1] = cells[i - 1][j][1] + 1;
      }
    }
  }

  repr(i, r + 1) {
    rep(j, c) {
      if (cells[i][j][0] == 0) {
        cells[i][j][2] = 0;
      } else {
        cells[i][j][2] = cells[i + 1][j][2] + 1;
      }
    }
  }

  int ans = 0;
  repl(i, k, r + 2 - k) {
    repl(j, k - 1, c - k + 1) {
      bool ok = true;
      rep(l, k) {
        if (cells[i][j + l][1] < k - l || cells[i][j + l][2] < k - l) {
          ok = false;
          break;
        }
        if (cells[i][j - l][1] < k - l || cells[i][j - l][2] < k - l) {
          ok = false;
          break;
        }
      }
      if (ok) ans++;
    }
  }

  print(ans);

  return 0;
}