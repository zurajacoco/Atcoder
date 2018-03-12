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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(all(a)), sort(all(b)), sort(all(c));
    ll num[n], sum[n] = {};
    rep(i, n) {
        auto j = upper_bound(all(c), b[i]) - c.begin();
        num[i] = n - j;
    }
    rep(i, n) {
        if (i == 0) sum[i] = num[i];
        else sum[i] = sum[i - 1] + num[i];
    }
    ll ans = 0;
    rep(i, n) {
        auto j = upper_bound(all(b), a[i]) - b.begin();
        if (j == 0) ans += sum[n - 1];
        else ans += (sum[n - 1] - sum[j - 1]);
    }
    cout << ans << endl;
    return 0;
}