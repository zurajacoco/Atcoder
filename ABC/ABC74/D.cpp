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
typedef pair<int, P> PIP;

#define INF INT_MAX/3

int a[300][300], b[300][300];

int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i, n)rep(j, n) cin >> a[i][j];
    bool ok = true;
    rep(i, n)rep(j, n)rep(k, n) if (a[j][i] + a[i][k] < a[j][k]) ok = false;
    if (ok) {
        ll ans = 0;
        rep(i, n)repl(j, i, n) {
            bool used = true;
            rep(k, n) if (i != k && j != k && a[i][j] == a[i][k] + a[k][j]) used = false;
            if (used) ans += a[i][j];
        }
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}