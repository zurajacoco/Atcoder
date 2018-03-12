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
typedef pair<P, int> PIP;

#define INF INT_MAX/3

int mp[50][50];
int dd[] = {1, 0, -1, 0, 1};

int main(){
    cin.sync_with_stdio(false);
    int r, c;
    cin >> r >> c;
    P s, g;
    cin >> s.fi >> s.se >> g.fi >> g.se;
    s.fi--, s.se--, g.fi--, g.se--;
    rep(i, r)rep(j, c) {
        char a;
        cin >> a;
        if (a == '.') mp[i][j] = -1;
        else mp[i][j] = 1;
    }
    queue<PIP> q;
    q.push(PIP(s, 0));
    while(q.size()) {
        PIP p = q.front();
        q.pop();
        if (mp[p.fi.fi][p.fi.se] >= 0) continue;
        mp[p.fi.fi][p.fi.se] = p.se;
        if (p.fi == g) break;
        rep(i, 4) {
            int x = p.fi.se + dd[i], y = p.fi.fi + dd[i + 1];
            if (mp[y][x] < 0) q.push(PIP(P(y, x), p.se + 1));
        }
    }
    cout << mp[g.fi][g.se] << endl;
    return 0;
}