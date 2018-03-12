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

int w, n, k;
vector<int> a, b;
int dp[55][10005];

int main(){
    cin.sync_with_stdio(false);
    cin >> w >> n >> k;
    rep(i, n) {
        int s, t;
        cin >> s >> t;
        a.pb(s), b.pb(t);
    }

    rep(i, k + 1)rep(j, w + 1) dp[i][j] = -1;
    dp[0][0] = 0;
    int maxi = 0;
    rep(i, n)repr(j, k)repr(l, w + 1) {
        if (dp[j][l] != INF && l + a[i] <= w) {
            maxch(dp[j + 1][l + a[i]], dp[j][l] + b[i]);
            maxch(maxi, dp[j + 1][l + a[i]]);
        }
    }
    cout << maxi << endl;

    return 0;
}