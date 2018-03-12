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
    int h, w, n;
    cin >> h >> w >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    int panel[w];
    int num = 0, idx = 0;
    rep(i, h) {
        if (i % 2 == 0) {
            rep(j, w) {
                panel[j] = idx + 1;
                num++;
                if (num == a[idx]) {
                    idx++;
                    num = 0;
                }
            }
        } else {
            repr(j, w, 0) {
                panel[j] = idx + 1;
                num++;
                if (num == a[idx]) {
                    idx++;
                    num = 0;
                }
            }
        }

        rep(j, w) cout << panel[j] << ((j < w - 1) ? " " : "\n");
    }
    return 0;
}