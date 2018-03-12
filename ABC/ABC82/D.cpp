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

int main(){
  cin.sync_with_stdio(false);
  string s;
  int x, y;
  cin >> s >> x >> y;
  s += "T";
  int sx = 0, sy = 0, p = 0;
  while(p < s.size() && s[p] == 'F') sx++, p++;
  vector<int> xx, yy;
  bool dx = false;
  int cnt = 0, sumx = 0, sumy = 0;
  repl(i, p + 1, s.size()) {
    if (s[i] == 'T') {
      if (dx) {
        if (cnt > 0) xx.pb(cnt);
        sumx += cnt;
      } else {
        if (cnt > 0) yy.pb(cnt);
        sumy += cnt;
      }
      dx = !dx;
      cnt = 0;
    } else {
      cnt++;
    }
  }

  if (abs(x - sx) > sumx || abs(y - sy) > sumy) {
    cout << "No" << endl;
  } else {
    sumx -= abs(x - sx); sumy -= abs(y - sy);
    if (sumx % 2 == 1 || sumy % 2 == 1) {
      cout << "No" << endl;
    } else {
      sumx /= 2, sumy /= 2;
      bool ok = true;
      bool num[8001];
      memset(num, 0, sizeof(num));
      num[0] = true;
      rep(i, xx.size())repr(j, 8001, 0) {
        if (num[j]) num[j + xx[i]] = true;
      }
      if (!num[sumx]) ok = false;
      memset(num, 0, sizeof(num));
      num[0] = true;
      rep(i, yy.size())repr(j, 8001, 0) {
        if (num[j]) num[j + yy[i]] = true;
      }
      if (!num[sumy]) ok = false;
      if(ok) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}