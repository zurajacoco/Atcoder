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

ll  binarysearch(vector<ll> &v, ll t) {
  int s = 0, e = v.size(), m;
  if (v[s] > t) return -1;
  if (v[e - 1] < t) return e - 1;
  while(true) {
    m = (s + e) / 2;
    if (v[m] <= t) s = m;
    else e = m;
    if (e - s == 1) break;
  }
  return s;
}


int main(){
  cin.sync_with_stdio(false);
  int n, q;
  cin >> n >> q;

  vector<ll> x(n, 0);
  ll sum[n] = {};
  cin >> x[0];
  x[0] += 1000000000;
  sum[0] = x[0];
  repl(i, 1, n) {
    cin >> x[i];
    x[i] += 1000000000;
    sum[i] = sum[i - 1] + x[i];
  }

  rep(i, q){
    ll t;
    cin >> t;
    t += 1000000000;

    ll p = binarysearch(x, t);

    ll ans = 0;
    if (p >= 0) {
     ans = sum[n - 1] - 2 * sum[p] - (n - 2 *(p + 1)) * t;
   } else if (p < 0) {
     ans = sum[n - 1] - (n - 2 * (p + 1)) * t;
   }

   print(ans);
 }

 return 0;
}