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

set<int> edge[2];

int main(){
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        if (a == 1) edge[0].insert(b);
        else if (b == 1) edge[0].insert(a);
        if (a == n) edge[1].insert(b);
        else if (b == n) edge[1].insert(a);
    }

    if (edge[0].count(n)) {
        cout << "POSSIBLE" << endl;
    } else {
        bool ok = false;
        each(i, edge[0]) {
            ok |= edge[1].count(i);
            if (ok) break;
        }
        if (ok) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}