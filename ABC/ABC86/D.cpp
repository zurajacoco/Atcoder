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

int grid[2000][2000];

int main(){
    cin.sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int x, y;
    char c;
    rep(i, n) {
        cin >> x >> y >> c;
        y %= (2 * k);
        if (c == 'W') x += k;
        if (y >= k) y -= k, x += k;
        x %= (2 * k);
        grid[y][x]++;
        cout << x << " " << y << endl;
    }
    // rep(i, k)rep(j, 2 * k) cout << grid[i][j] << ((j == 2 * k - 1) ? "\n" : " ");
    rep(i, 2 * k)repl(j, 1, k) grid[j][i] += grid[j - 1][i];
    // rep(i, 2 * k) cout << grid[k - 1][i] << ((i == 2 * k - 1) ? "\n" : " ");
    int ans = 0;
    rep(i, k + 1) {
        int sum = 0;
        repl(j, i, i + k) {
            sum += grid[k - 1][j];
        }
        maxch(ans, sum);
    }
    cout << ans << endl;
    return 0;
}