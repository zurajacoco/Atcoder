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
#define MOD 1000000009

ll h, w, d;

bool range(ll a, ll b) {
    return 0 <= a && a < h && 0 <= b && b < w;
}

char change(char c) {
    char res;
    if (c == 'R') res = 'Y';
    else if (c == 'Y') res = 'G';
    else if (c == 'G') res = 'B';
    else res = 'R';
    return res;
}

int main(){
    cin.sync_with_stdio(false);
    cin >> h >> w >> d;

    char p[h][w];
    rep(i, h)rep(j, w) p[i][j] = 'R';

    int num = h * w;
    priority_queue<PIP> q;
    bool visited[h][w];
    rep(i, h) {
        rep(j, w) {
            visited[i][j] = false;
        }
    }
    rep(i, d) q.push(PIP(num--, P(0, i)));
    while(q.size() > 0) {
        PIP pip = q.top(); q.pop();
        int i = pip.se.fi, j = pip.se.se;
        if (visited[i][j]) continue;
        visited[i][j] = true;
        repl(k, 0, d + 1) {
            if (range(i + k, j + d - k) && !visited[i + k][j + d - k] && p[i][j] == p[i + k][j + d - k]) {
                p[i + k][j + d - k] = change(p[i][j]);
                q.push(PIP(num--, P(i + k, j + d - k)));
            }
            if (range(i + k, j - d + k) && !visited[i + k][j - d + k] && p[i][j] == p[i + k][j - d + k]) {
                p[i + k][j - d + k] = change(p[i][j]);
                q.push(PIP(num--, P(i + k, j - d + k)));
            }
        }

        repl(k, -d, 0) {
            if (range(i + k, j + d + k) && !visited[i + k][j + d + k] && p[i][j] == p[i + k][j + d + k]) {
                p[i + k][j + d + k] = change(p[i][j]);
                q.push(PIP(num--, P(i + k, j + d + k)));
            }
            if (range(i + k, j - d - k) && !visited[i + k][j - d - k] && p[i][j] == p[i + k][j - d - k]) {
                p[i + k][j - d - k] = change(p[i][j]);
                q.push(PIP(num--, P(i + k, j - d - k)));
            }
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << p[i][j];
        }
        cout << endl;
    }
    return 0;
}