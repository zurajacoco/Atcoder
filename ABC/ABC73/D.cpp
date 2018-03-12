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

int rr[8];
int d[200][200];

int main(){
    cin.sync_with_stdio(false);
    int n, m, r;
    cin >> n >> m >> r;
    rep(i, r) {
        cin >> rr[i];
        rr[i]--;
    }
    rep(i, n)rep(j, n) if(i != j) d[i][j] = INF;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = d[b][a] = c;
    }
    rep(k, n)rep(i, n)rep(j, n) minch(d[i][j], d[i][k] + d[k][j]);
    int ans = INF;
    sort(rr, rr + r);
    do {
        int c = 0;
        rep(i, r - 1) {
            c += d[rr[i]][rr[i + 1]];
        }
        minch(ans, c);
    } while(next_permutation(rr, rr + r));
    cout << ans << endl;
    return 0;
}