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

ll d[50][51];
ll maxi[2501];

int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i, n)rep(j, n) cin >> d[i][j + 1];
    rep(i, n)repl(j, 1, n + 1) d[i][j] += d[i][j - 1];
    rep(i, n)repl(j, 1, n + 1)repl(k, i, n)repl(l, j, n + 1) {
        ll tmp = 0;
        repl(m, i, k + 1) tmp += d[m][l] - d[m][j - 1];
        maxch(maxi[(k - i + 1) * (l - j + 1)], tmp);
    }
    repl(i, 1, 2501) maxch(maxi[i], maxi[i - 1]);
    int q;
    cin >> q;
    rep(i, q) {
        int p;
        cin >> p;
        cout << maxi[p] << endl;
    }
    return 0;
}