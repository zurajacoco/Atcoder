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
typedef pair<ll, ll> P;
typedef pair<P, ll> PL;

#define INF INT_MAX/3

int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    ll x[n];
    P goods[n];
    vector<PL> v[n];
    vector<PL> vv;
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> goods[i].fi;
    rep(i, n) cin >> goods[i].se;
    repl(i, 1, n) x[i] += x[i - 1];
    repl(i, 1, 1 << n) {
        PL tmp = PL(P(0, 0), 0);
        rep(j, n) {
            if (i & (1 << j)) {
                tmp.fi.fi += goods[j].fi;
                tmp.fi.se += goods[j].se;
            }
        }
        tmp.se = i;
        v[bcnt(i) - 1].pb(tmp);
        vv.pb(tmp);
    }
    rep(i, n) sort(all(v[i]));
    sort(all(vv));
    ll ans = 0;
    rep(i, n) {
        int j = 0;
        while(j < v[i].size() && v[i][j].fi.fi <= x[i]) j++;
        j = max(0, j - 1);
        ll tmp = v[i][j].se;
        j = 1;
        while(j < (1 << n) && vv[j].fi.fi <= x[i]) {
            if ((vv[j].se & tmp) == 0) maxch(ans, vv[j].fi.se);
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}