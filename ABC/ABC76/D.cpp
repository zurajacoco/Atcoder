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
typedef pair<double, double> P;

#define INF INT_MAX/3

int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    double t[n], v[n + 2];
    rep(i, n) cin >> t[i];
    repl(i, 1, n + 1) cin >> v[i];
    v[0] = v[n + 1] = 0;
    repr(i, n + 1, 1) minch(v[i], v[i + 1] + t[i - 1]);
    repl(i, 1, n + 1) minch(v[i], v[i - 1] + t[i - 1]);
    double len = 0, vv = 0, tt;
    repl(i, 1, n + 1) {
        if (v[i] <= v[i + 1]) {
            if (v[i] - vv < t[i - 1]) {
                tt = v[i] - vv;
                len += ((vv * tt + 0.5 * tt * tt) + v[i] * (t[i - 1] - tt));
                vv = v[i];
            } else {
                tt = t[i - 1];
                len += (vv * tt + 0.5 * tt * tt);
                vv += tt;
            }
        } else {
            if ((v[i] - vv) + (v[i] - v[i + 1]) > t[i - 1]) {
                tt = (v[i + 1] - vv + t[i - 1]) / 2.0;
                double vvv = vv + tt, ttt = t[i - 1] - tt;
                len += ((vv * tt + 0.5 * tt * tt) + (vvv * ttt - 0.5 * ttt * ttt));
            } else {
                tt = v[i] - vv;
                double vvv = v[i], ttt = v[i] - v[i + 1];
                len += ((vv * tt + 0.5 * tt * tt) + (vvv * ttt - 0.5 * ttt * ttt) + v[i] * (t[i - 1] - tt - ttt));
            }
            vv = v[i + 1];
        }
    }
    printf("%.8f\n", len);
    return 0;
}