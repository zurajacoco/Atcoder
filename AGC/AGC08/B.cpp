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


int main(){
    cin.sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll a[n], sum[n], pre[n];
    rep(i, n) {
        cin >> a[i];
        if (i == 0) sum[i] = a[i], pre[i] = ((a[i] > 0) ? a[i] : 0);
        else sum[i] = a[i] + sum[i - 1], pre[i] = pre[i - 1] + ((a[i] > 0) ? a[i] : 0);
    }

    ll ans = max(sum[k - 1], 0LL) + pre[n - 1] - pre[k - 1];
    repl(i, k, n) {
        maxch(ans, max(sum[i] - sum[i - k], 0LL) + pre[i - k] + pre[n - 1] - pre[i]);
    }
    cout << ans << endl;
    return 0;
}