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

int num[301];

int main(){
    cin.sync_with_stdio(false);
    int n, ng[3];
    cin >> n >> ng[0] >> ng[1] >> ng[2];
    if (n == ng[0] || n == ng[1] || n == ng[2]) cout << "NO" << endl;
    else {
        rep(i, n + 1) num[i] = INF;
        num[n] = 0;
        repr(i, n + 1, 0) {
            repl(j, 1, 4) {
                if (i - j >= 0 && i - j != ng[0] && i - j != ng[1] && i - j != ng[2]) {
                    minch(num[i - j], num[i] + 1);
                }
            }
        }
        if (num[0] == INF || num[0] > 100) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}