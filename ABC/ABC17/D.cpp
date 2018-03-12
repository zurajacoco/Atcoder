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
#define MOD 1000000007

int f[100005];
vector<int> v[100005];
int id[100005];
ll dp[100005];
ll sum[100005];

int main(){
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    rep(i, n) {
        cin >> f[i];
        v[f[i]].pb(i);
    }

    dp[0] = 1;
    sum[0] = 0;
    sum[1] = (f[0] == f[1]) ? 0 : 1;
    id[f[0]]++;
    int maxi = -1;
    repl(i, 1, n) {
        int tmp = ((id[f[i]]) ? v[f[i]][id[f[i]] - 1] : -1);
        if (maxi < tmp) {
            maxi = tmp;
            repl(j, maxi, i - 1) sum[i] = (sum[i] + dp[j]) % MOD;
        } else if (i > 1) {
            sum[i] = (sum[i - 1] + dp[i - 2]) % MOD;
        }
        id[f[i]]++;
        dp[i] = (dp[i - 1] + sum[i]) % MOD;
    }

    cout << dp[n - 1] << endl;

    return 0;
}