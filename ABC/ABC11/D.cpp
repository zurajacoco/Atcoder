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

double rate[1001][1001];

int main(){
    cin.sync_with_stdio(false);
    ll n, d, x, y;
    cin >> n >> d >> x >> y;
    x = abs(x), y = abs(y);
    if (x % d != 0 || y % d != 0) {
        printf("%.20f\n", 0);
    } else {
        ll tx = x / d, ty = y / d;
        ll rest = n - (tx + ty);
        if (rest < 0 || rest % 2 == 1) {
            printf("%.20f\n", 0);
        } else {
            rest /= 2;
            rate[0][0] = 1;
            repl(i, 1, 1001)rep(j, i + 1) {
                if (j == 0) rate[i][j] = rate[i - 1][j] / 2.0;
                else rate[i][j] = (rate[i - 1][j] + rate[i - 1][j - 1]) / 2.0;
            }
            double ans = 0;
            rep(i, rest + 1) {
                int left = tx + i, upper = ty + rest - i;
                ans += (rate[n][tx + i * 2] * rate[tx + i * 2][left] * rate[n - (tx + i * 2)][upper]);
            }
            printf("%.20f\n", ans);
        }
    }
    return 0;
}