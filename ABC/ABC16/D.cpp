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
typedef long double D;
typedef complex<D> P;

struct L : public vector<P> {
  L(const P& a,const P &b){
    push_back(a);
    push_back(b);
  }
};
typedef vector<P> G;

#define INF INT_MAX/3
#define MAX_N 1000000001
#define X real()
#define Y imag()
const D eps=1e-8;
const D inf=1e12;
const D PI=acos(-1);


namespace std{
  bool operator<(const P& a,const P& b){
    return abs(a.X-b.X)<eps?a.Y<b.Y:a.X<b.X;
  }
}
bool cmp_x(const P& a,const P& b){ return abs(a.X-b.X)<eps?a.Y<b.Y:a.X<b.X; }
bool cmp_y(const P& a,const P& b){ return abs(a.Y-b.Y)<eps?a.X<b.X:a.Y<b.Y; }
D cross(P a,P b){ return (conj(a)*b).Y; }
D dot(P a,P b){ return (conj(a)*b).X; }
D toRag(D deg){ return deg*PI/180.0; }
P rot(P base,P a,D theta){ return base+polar(abs(a-base),arg(a-base)+theta); }

int ccw(P a,P b,P c) {
  b=b-a;c=c-a;
  if(cross(b,c)>0) return +1;       // counter clockwise
  if(cross(b,c)<0) return -1;       // clockwise
  if(dot(b,c)<0)   return +2;       // c--a--b on line
  if(norm(b)<norm(c)) return -2;       // a--b--c on line
  return 0;
}

bool intersectSS(L s,L t){
  return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1])<=0&&ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1])<=0;
}

int main(){
    cin.sync_with_stdio(false);
    D ax, ay, bx, by, n, vx, vy;
    cin >> ax >> ay >> bx >> by >> n;
    L line(P(ax, ay), P(bx, by));
    G g;

    rep(i, n) {
        cin >> vx >> vy;
        g.pb(P(vx, vy));
    }
    g.pb(g[0]);

    int cnt = 0;
    rep(i, n) {
        cnt += intersectSS(line, L(g[i], g[i + 1]));
    }

    cout << cnt / 2 + 1 << endl;

    return 0;
}