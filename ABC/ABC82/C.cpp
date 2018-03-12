#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,a,b) for(int i=(int)(a-1);i>=b;i--)
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

int a[100010];

int main(){
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  rep(i, n) cin >> a[i];
  sort(a, a + n);
  int num = 0, cnt = 0, ans = 0;
  a[n + 1] = 1e9 + 1;
  rep(i, n + 1) {
    if (num != a[i]) {
      if (num <= cnt) ans += (cnt - num);
      else ans += cnt;
      num = a[i];
      cnt = 1;
    } else {
      cnt++;
    }
  }
  cout << ans << endl;
  return 0;
}