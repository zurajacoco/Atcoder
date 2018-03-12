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
    ll n, h;
    cin >> n >> h;
    vector<P> a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i].fi >> b[i].fi;
        a[i].se = b[i].se = i;
        c[i] = P(a[i].fi, b[i].fi);
    }
    sort(all(a)); sort(all(b));
    reverse(all(a)); reverse(all(b));
    ll cnt = 0;
    if (c[a[0].se].se >= h) {
        cout << 1 << endl;
    } else {
        int i = 0;
        while(h > 0 && i < n && b[i].fi >= a[0].fi) {
            h -= b[i].fi;
            i++;
            cnt++;
        }
        if (h > 0) {
            cnt = cnt + h / a[0].fi + (h % a[0].fi != 0);
        }
        cout << cnt << endl;
    }
    return 0;
}