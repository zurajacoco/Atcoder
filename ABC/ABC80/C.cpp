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

#define INF (1e18)

int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    int f[n] = {};
    rep(i, n){
        rep(j, 5)rep(k, 2) {
            int tmp;
            cin >> tmp;
            f[i] = f[i] * 2 + tmp;
        }
    }
    int p[n][11];
    rep(i, n)rep(j, 11) cin >> p[i][j];
    ll maxi = -INF;
    repl(i, 1, 1 << 10) {
        ll tmp = 0;
        rep(j, n) tmp += p[j][bcnt((i & f[j]))];
        maxch(maxi, tmp);
    }
    cout << maxi << endl;
    return 0;
}