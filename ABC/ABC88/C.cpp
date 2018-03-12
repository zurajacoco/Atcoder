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
    int c[3][3];
    rep(i, 3)rep(j, 3) {
        cin >> c[i][j];
    }
    bool ok = true;
    if (c[0][1] - c[0][0] != c[1][1] - c[1][0] || c[1][1] - c[1][0] != c[2][1] - c[2][0]) ok = false;
    if (c[0][1] - c[0][2] != c[1][1] - c[1][2] || c[1][1] - c[1][2] != c[2][1] - c[2][2]) ok = false;
    if (c[1][0] - c[0][0] != c[1][1] - c[0][1] || c[1][1] - c[0][1] != c[1][2] - c[0][2]) ok = false;
    if (c[1][0] - c[2][0] != c[1][1] - c[2][1] || c[1][1] - c[2][1] != c[1][2] - c[2][2]) ok = false;
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}