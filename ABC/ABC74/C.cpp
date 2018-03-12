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

int main(){
    cin.sync_with_stdio(false);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    bool water[f + 1] = {}, sugger[f + 1] = {};
    set<int> w, s;
    water[0] = sugger[0] = true;
    s.insert(0);
    rep(i, f + 1) {
        if (water[i] && i + 100 * a <= f) {
            water[i + 100 * a] = true;
            w.insert(i + 100 * a);
        }
        if (water[i] && i + 100 * b <= f) {
            water[i + 100 * b] = true;
            w.insert(i + 100 * b);
        }
        if (sugger[i] && i + c <= f) {
            sugger[i + c] = true;
            s.insert(i + c);
        }
        if (sugger[i] && i + d <= f) {
            sugger[i + d] = true;
            s.insert(i + d);
        }
    }
    int p = 100 * a, q = 0;
    double maxi = 0;
    each(i, w)each(j, s) {
        if (i * e / 100 < j || i + j > f) break;
        if (maxi < (double)j / (double)(i + j)) {
            maxi = (double)j / (double)(i + j);
            p = i + j, q = j;
        }
    }
    cout << p << " " << q << endl;
    return 0;
}