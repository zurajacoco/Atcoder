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

char s[52][52];

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    cin.sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    memset(s, '.', sizeof('.'));
    rep(i, h)rep(j, w) cin >> s[i + 1][j + 1];
    repl(i, 1, h + 1)repl(j, 1, w + 1) {
        if (s[i][j] == '.') {
            int tmp = 0;
            rep(k, 8) {
                int x = j + dx[k], y = i + dy[k];
                if (s[y][x] == '#') tmp++;
            }
            s[i][j] = (char)(tmp + '0');
        }
        cout << s[i][j];
        if (j == w) cout << endl;
    }
    return 0;
}