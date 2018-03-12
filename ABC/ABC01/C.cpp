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

string dir[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "C"};
double lim[] = {2.5, 15.5, 33.5, 54.5, 79.5, 107.5, 138.5, 171.5, 207.5, 244.5, 284.5, 326.5, 120000};

int main(){
    cin.sync_with_stdio(false);
    int deg, dis;
    cin >> deg >> dis;
    deg *= 10;
    if (deg < 1125 || deg >= 34875) deg = 0;
    else deg = (deg + 1125) / 2250;
    double s = dis / 6.0;
    int p = 0;
    rep(i, 13) {
        if (s < lim[i]) {
            p = i;
            break;
        }
    }
    if (p == 0) deg = 16;
    cout << dir[deg] << " " << p << endl;
    return 0;
}