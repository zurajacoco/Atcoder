#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF INT_MAX/3

#define MAX_N 1000

int main(){
    cin.sync_with_stdio(false);
    int n, x;
    cin >> n >> x;

    int a[n];
    int sum[n - 1];
    rep(i, n) {
        cin >> a[i];
        if (i > 0) sum[i - 1] = a[i] + a[i - 1];
    }

    ll cnt = 0;
    rep(i, n - 2) {
        if (sum[i] <= x) continue;
        int d = sum[i] - x;
        if (d > a[i + 1]) {
            sum[i + 1] -= a[i + 1];
        } else {
            sum[i + 1] -= d;
        }
        cnt += d;
    }
    if (sum[n - 2] > x) cnt += sum[n - 2] - x;

    cout << cnt << endl;

    return 0;
}