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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int div[n] = {};
    rep(i, n - 1) {
        repl(j, i + 1, n) {
            if (a[j] % a[i] == 0) div[j]++;
            if (a[i] == a[j]) div[i]++;
        }
    }
    double ans = 0;
    rep(i, n) {
        if (div[i] % 2 == 1) ans += 0.5;
        else ans += (double)(div[i] + 2.0) / (2 * div[i] + 2.0);
    }
    printf("%.10f\n", ans);
    return 0;
}