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

int binarysearch(vector<P> &v, int t) {
  int s = 0, e = v.size(), m;
  if (v[s].fi > t) return -1;
  if (v[e - 1].fi < t) return e - 1;
  while(true) {
    m = (s + e) / 2;
    if (v[m].fi < t) s = m;
    else e = m;
    if (e - s == 1) break;
  }
  return s;
}

int main(){
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  vector<P> v(m), vv(m);
  rep(i, m) {
    cin >> v[i].fi >> v[i].se;
    vv[i].fi = v[i].se;
    vv[i].se = v[i].fi;
  }

  sort(all(v));
  sort(all(vv));

  ll ans = 0;
  repl(i, 1, n + 1) {
    repl(j, 1, n + 1) {
      ll tmp = 0;
      int p = lower_bound(all(v), P(i, 1)) - v.begin();
      if (p == m || v[p].fi != i) continue;
      int q = lower_bound(all(vv), P(j, 1)) - vv.begin();
      if (q == m || vv[q].fi != j) continue;

      while (p < m && v[p].fi == i) {
        while(q < m && vv[q].fi == j && vv[q].se < v[p].se) q++;
        if (q == m || vv[q].fi > j) break;
        if (vv[q].se == v[p].se) tmp++;
        p++;
      }
      ans += tmp * tmp;
    }
  }
  print(ans);

  return 0;
}