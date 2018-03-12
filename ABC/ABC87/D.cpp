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

#define INF LONG_MAX/3

struct edge {ll u, c;};

vector<edge> v[100000];
ll d[100000];
bool visited[100000];

int main(){
    cin.sync_with_stdio(false);
    ll n, m, mini;
    cin >> n >> m;

    mini = n;
    rep(i, m) {
        ll l, r, c;
        cin >> l >> r >> c;
        l--, r--;
        edge e1{r, c}, e2{l, -c};
        v[l].pb(e1);
        v[r].pb(e2);
        minch(mini, l);
    }

    rep(i, n) d[i] = INF;
    d[mini] = 0;

    bool ok = true;
    while (true) {
        queue<ll> q;
        q.push(mini);
        while(q.size()) {
            int p = q.front(); q.pop();
            if (visited[p]) continue;
            visited[p] = true;
            rep(i, v[p].size()) {
                int u = v[p][i].u, c = v[p][i].c;
                if (!visited[u] && d[u] == INF) {
                    d[u] = d[p] + c;
                    q.push(u);
                } else if (visited[u] && d[u] != d[p] + c) {
                    ok = false;
                }
            }
        }

        mini = -1;
        rep(i, n) if (!visited[i] && v[i].size() > 0) mini = i;
        if (mini == -1) break;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}