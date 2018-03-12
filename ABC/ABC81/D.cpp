#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,a,b) for(int i=(int)(a-1);i>=(int)(b);i--)
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

ll a[51];

int main(){
  cin.sync_with_stdio(false);
  int n, mini = INF, maxi = -INF, p, q;
  cin >> n;
  rep(i, n) {
    cin >> a[i];
    if (mini > a[i]) mini = a[i], p = i;
    if (maxi < a[i]) maxi = a[i], q = i;
  }
  vector<P> ans;
  if (mini < 0 && maxi > 0) {
    if (abs(mini) > abs(maxi)) {
      rep(i, n) {
        if (i == p) continue;
        ans.pb(P(p + 1, i + 1));
        a[i] += mini;
      }
      maxi += mini;
      ans.pb(P(p + 1, p + 1));
      a[p] += mini;
      mini += mini;
    } else {
      rep(i, n) {
        if (i == q) continue;
        ans.pb(P(q + 1, i + 1));
        a[i] += maxi;
      }
      mini += maxi;
      ans.pb(P(q + 1, q + 1));
      a[q] += maxi;
      maxi += maxi;
    }
  }
  if (mini <= 0 && maxi <= 0) {
    repr(i, n, 1) if (a[i - 1] > a[i]) {
      ans.pb(P(i + 1, i));
      a[i - 1] += a[i];
    }
  } else {
    repl(i, 1, n) if (a[i - 1] > a[i]) {
      ans.pb(P(i, i + 1));
      a[i] += a[i - 1];
    }
  }
  cout << ans.size() << endl;
  rep(i, ans.size()) cout << ans[i].fi << " " << ans[i].se << endl;
  return 0;
}