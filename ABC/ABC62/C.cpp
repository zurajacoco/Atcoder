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

int main(){
    cin.sync_with_stdio(false);
    ll h, w;
    cin >> h >> w;

    if (h % 3 == 0 || w % 3 == 0) {
        cout << 0 << endl;
    } else {
        ll ans = INF;
        ll a = (h / 3) * w, b = ((h - (h / 3)) / 2) * w, c = w * h - a - b;
        minch(ans, max(abs(a - b), max(abs(a - c), abs(b - c))));
        a = (h / 3 + 1) * w, b = ((h - (h / 3 + 1)) / 2) * w, c = w * h - a - b;
        minch(ans, max(abs(a - b), max(abs(a - c), abs(b - c))));
        a = (h / 3) * w, b = (h - (h / 3)) * (w / 2), c = w * h - a - b;
        minch(ans, max(abs(a - b), max(abs(a - c), abs(b - c))));
        a = (h / 3 + 1) * w, b = (h - (h / 3 + 1)) * (w / 2), c = w * h - a - b;
        minch(ans, max(abs(a - b), max(abs(a - c), abs(b - c))));
        swap(h, w);
        a = (h / 3) * w, b = ((h - (h / 3)) / 2) * w, c = w * h - a - b;
        minch(ans, max(abs(a - b), max(abs(a - c), abs(b - c))));
        a = (h / 3 + 1) * w, b = ((h - (h / 3 + 1)) / 2) * w, c = w * h - a - b;
        minch(ans, max(abs(a - b), max(abs(a - c), abs(b - c))));
        a = (h / 3) * w, b = (h - (h / 3)) * (w / 2), c = w * h - a - b;
        minch(ans, max(abs(a - b), max(abs(a - c), abs(b - c))));
        a = (h / 3 + 1) * w, b = (h - (h / 3 + 1)) * (w / 2), c = w * h - a - b;
        minch(ans, max(abs(a - b), max(abs(a - c), abs(b - c))));
        cout << ans << endl;
    }
    return 0;
}