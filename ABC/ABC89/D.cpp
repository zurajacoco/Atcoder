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

ll a[90010];
bool check[90010];
P p[90010];

int main(){
    cin.sync_with_stdio(false);
    int h, w, d;
    cin >> h >> w >> d;
    rep(i, h)rep(j, w) {
        int n;
        cin >> n;
        p[n] = P(i, j);
    }

    repr(i, h * w + 1, 1) {
        if (check[i]) continue;
        check[i] = true;
        a[i] = 0;
        int j = i - d;
        while(j >= 1) {
            a[j] = abs(p[j + d].fi - p[j].fi) + abs(p[j + d].se - p[j].se) + a[j + d];
            check[j] = true;
            j -= d;
        }
    }

    int q;
    cin >> q;
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << a[l] - a[r] << endl;
    }
    return 0;
}