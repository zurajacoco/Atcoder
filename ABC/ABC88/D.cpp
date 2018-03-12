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
typedef pair<int, P> PIP;

#define INF INT_MAX/3

int h, w;
char s[50][50];
int d[50][50];
bool visited[50][50];
int dd[] = {-1, 0, 1, 0, -1};

bool range(int y, int x) {return 0 <= x && x < w && 0 <= y && y < h;}

int main(){
    cin.sync_with_stdio(false);
    cin >> h >> w;
    int white = 0;
    rep(i, h)rep(j, w) {
        cin >> s[i][j];
        if (s[i][j] == '.') white++;
        d[i][j] = INF;
        visited[i][j] = false;
    }

    queue<PIP> q;
    q.push(PIP(1, P(0, 0)));
    while(q.size()) {
        PIP p = q.front();
        q.pop();
        if (visited[p.se.fi][p.se.se]) continue;
        visited[p.se.fi][p.se.se] = true;
        d[p.se.fi][p.se.se] = p.fi;
        rep(i, 4) {
            int x = p.se.se + dd[i], y = p.se.fi + dd[i + 1];
            if (range(y, x) && s[y][x] == '.' && !visited[y][x]) {
                q.push(PIP(p.fi + 1, P(y, x)));
            }
        }
    }

    if (!visited[h - 1][w - 1]) cout << -1 << endl;
    else cout << white - d[h - 1][w - 1] << endl;
    return 0;
}