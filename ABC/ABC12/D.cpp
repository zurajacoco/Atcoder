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

int d[300][300];

int main(){
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i, n)rep(j, n) {
        if (i == j) d[i][j] = 0;
        else d[i][j] = INF;
    }
    rep(i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        d[a][b] = d[b][a] = t;
    }
    rep(i, n)rep(j, n)rep(k, n) minch(d[j][k], d[j][i] + d[i][k]);

    int mini = INF;
    rep(i, n) {
        int maxi = 0;
        rep(j, n) {
            maxch(maxi, d[i][j]);
        }
        minch(mini, maxi);
    }
    cout << mini << endl;
    return 0;
}