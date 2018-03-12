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
    string s;
    cin >> s;
    char ans[] = {s[0], ' ', s[1], ' ', s[2], ' ', s[3], '=', '7', '\0'};
    int a[4] = {s[0] - '0', s[1] - '0', s[2] - '0', s[3] - '0'}, e;
    rep(i, 1 << 3) {
        e = a[0];
        rep(j, 3) {
            if (i & (1 << j)) e -= a[j + 1], ans[j * 2 + 1] = '-';
            else e += a[j + 1], ans[j * 2 + 1] = '+';
        }
        if (e == 7) break;
    }
    cout << ans << endl;
    return 0;
}