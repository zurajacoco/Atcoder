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
    ll n, w;
    cin >> n >> w;
    P things[n];
    rep(i, n) cin >> things[i].fi >> things[i].se;
    ll w1;
    w1 = things[0].fi;
    sort(things, things + n); reverse(things, things + n);
    ll sum[4][100] = {}, idx[4] = {1, 1, 1, 1};
    rep(i, n) {
        ll j = things[i].fi - w1;
        sum[j][idx[j]] = sum[j][idx[j] - 1] + things[i].se;
        idx[j]++;
    }
    ll maxi = 0;
    rep(a, idx[0])rep(b, idx[1])rep(c, idx[2])rep(d, idx[3]) {
        if (a * w1 + b * (w1 + 1) + c * (w1 + 2) + d * (w1 + 3) <= w) {
            maxch(maxi, sum[0][a] + sum[1][b] + sum[2][c] + sum[3][d]);
        }
    }
    cout << maxi << endl;
    return 0;
}