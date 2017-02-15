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

#define MAX_N 1000000

void unite(int, int, int);
int find(int, int);

PPI cities[MAX_N];

int main(){
    cin.sync_with_stdio(false);
    int n, k, l;
    cin >> n >> k >> l;

    rep(i, n + 1) {
        cities[i].fi.fi = cities[i].fi.se = i;
        cities[i].se = i;
    }

    int p, q;
    rep(i, k) {
        cin >> p >> q;
        unite(p, q, 0);
    }

    rep(i, l) {
        cin >> p >> q;
        unite(p, q, 1);
    }

    repl(i, 1, n + 1) {
        cities[i].fi.fi = find(cities[i].fi.fi, 0);
        cities[i].fi.se = find(cities[i].fi.se, 1);
    }

    sort(cities + 1, cities + n + 1);

    int j = 1, ans[n + 1];
    repl(i, 1, n + 1) {
        int road = cities[i].fi.fi, train = cities[i].fi.se;
        int cnt = 0;
        for (; j <= n && road == cities[j].fi.fi && train == cities[j].fi.se; j++){
            cnt++;
        }
        repl(k, i, j) {
            ans[cities[k].se] = cnt;
        }
        i = j - 1;
    }

    repl(i, 1, n) {
        cout << ans[i] << " ";
    }
    cout << ans[n] << endl;

    return 0;
}

void unite(int p, int q, int sw) {
    int a = find(p, sw);
    int b = find(q, sw);
    if (a == b) return;

    if (sw == 0) {
        cities[b].fi.fi = a;
    } else {
        cities[b].fi.se = a;
    }
}

int find(int p, int sw) {
    if (sw == 0) {
        return (cities[p].fi.fi == p) ? p : cities[p].fi.fi = find(cities[p].fi.fi, sw);
    } else {
        return (cities[p].fi.se == p) ? p : cities[p].fi.se = find(cities[p].fi.se, sw);
    }
}