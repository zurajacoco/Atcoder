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

#define INF INT_MAX/3

int main(){
    cin.sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    set<ll> ok, ng;
    ok.insert(0), ok.insert(1);
    ng.insert(1);
    repl(i, 2, 1000000) {
        bool f = true;
        each(j, ok) {
            if (ng.count(i + j)) {
                f = false;
                break;
            }
        }
        if (!f) continue;
        each(j, ok) ng.insert(i + j);
        ok.insert(i);
        if (ok.size() == 300) break;
    }
    // cout << ok.size() << endl;
    vector<ll> x;
    vector<P> y;
    vector<P> z;
    each(i, ok) x.pb(i);
    int idx = 0;
    rep(i, x.size() - 1)repl(j, i + 1, x.size()) {
        y.pb(P(x[i] + x[j], idx));
        z.pb(P(i + 1, j + 1));
        idx++;
    }
    sort(all(y));
    rep(i, n - 300) x.pb(0);
    rep(i, n) cout << x[i] << ((i < n - 1) ? " " : "\n");
    fflush(stdout);
    int q;
    cin >> q;
    rep(i, q) {
        ll num;
        cin >> num;
        if (i < 300) {
            auto j = lower_bound(all(y), P(num, 0)) - y.begin();
            cout << z[y[j].se].fi << " " << z[y[j].se].se << endl;
        } else {
            cout << "0 1" << endl;
        }
        fflush(stdout);
    }
    return 0;
}