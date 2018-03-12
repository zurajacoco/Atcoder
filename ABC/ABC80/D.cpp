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

int imos[200001][30];

int main(){
    cin.sync_with_stdio(false);
    int n, c;
    cin >> n >> c;
    memset(imos, 0, sizeof(imos));
    rep(i, n) {
        int s, t, r;
        cin >> s >> t >> r;
        imos[s * 2 - 1][r - 1]++;
        imos[t * 2][r - 1]--;
    }
    int maxi = 0;
    repl(i, 1, 200001) {
        int tmp = 0;
        rep(j, c) imos[i][j] += imos[i - 1][j], tmp += (imos[i][j] > 0);
        maxch(maxi, tmp);
    }
    cout << maxi << endl;
    return 0;
}