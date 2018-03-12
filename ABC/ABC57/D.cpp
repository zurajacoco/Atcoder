#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=0;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define print(x) cout << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<int, P> PIP;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001

ll c[51][51];

void combination() {
    rep(i, 51)rep(j, i + 1) {
        if (j == 0 || i == j) c[i][j] = 1;
        else c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
}


int main(){
    cin.sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    ll v[n];
    rep(i, n) cin >> v[i];

    sort(v, v + n, greater<ll>());

    double ave = 0;
    rep(i, a) ave += v[i];
    ave /= a;

    combination();

    int num = 0, in = 0;
    rep(i, n) {
        if (v[i] == v[a - 1]) {
            num++;
            if (i < a) in++;
        }
    }

    ll cnt = 0;
    if (v[0] == v[a - 1]) {
        repl(i, a, b + 1) cnt += c[num][i];
    } else {
        cnt += c[num][in];
    }
    printf("%.10f\n%ld\n", ave, cnt);
    return 0;
}