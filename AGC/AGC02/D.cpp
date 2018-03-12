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
#define MAX_N 100001

struct union_find {
    int rank[MAX_N], par[MAX_N];

    union_find(int n) { rep(i, n) rank[i] = 1, par[i] = i; }

    int find(int x) {
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;
        if(rank[x] > rank[y]) par[y] = x;
        else {
            par[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
    bool same(int x, int y) {
        x = find(x); y = find(y);
        return x == y;
    }
};

int main(){
    cin.sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m;


    return 0;
}