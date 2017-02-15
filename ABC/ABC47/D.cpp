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
#define dbg(x) cout<< #x"=" << x <<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<int, P> PIP;
typedef pair<P, P> PPP;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF INT_MAX

#define MAX_N 1000000001

int main(){
    cin.sync_with_stdio(false);
    int n, t;
    cin >> n >> t;

    int a[n];
    PIP cities[n];

    int maximum = 0, minimum = MAX_N, j = 0;
    int count[n] = {};
    rep(i, n) {
        cin >> a[i];
        if (minimum >= a[i]) {
            minimum = a[i];
            j = i;
        }
        cities[i].fi = a[i] - minimum;
        cities[i].se.fi = j;
        cities[i].se.se = i;
        count[j]++;
        count[i]++;
    }

    sort(cities, cities + n, greater<PIP>());
    /*rep(i, n) {
        cout << cities[i].se.fi << ", " << cities[i].se.se << endl;
    }*/


    int d = cities[0].fi;
    int cnt = 0;
    set<int> set;
    rep(i, n) {
        if (cities[i].fi != d) break;
        auto it1 = set.find(cities[i].se.fi), it2 = set.find(cities[i].se.se);
        if (it1 != set.end()) {
            count[cities[i].se.se]--;
            continue;
        }
        if (it2 != set.end()) {
            count[cities[i].se.fi]--;
            continue;
        }
        if (count[cities[i].se.fi] > count[cities[i].se.se]) {
            cnt += count[cities[i].se.fi];
            count[cities[i].se.se]--;
            set.insert(cities[i].se.fi);
            // cout << "a insert: " << cities[i].se.fi << endl;
        } else {
            cnt += count[cities[i].se.se];
            count[cities[i].se.fi]--;
            set.insert(cities[i].se.se);
            // cout << "b insert: " << cities[i].se.se << endl;
        }
    }

    cout << set.size() << endl;

    return 0;
}