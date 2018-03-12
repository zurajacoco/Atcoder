#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=0;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define print(x) cout << x << endl
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
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001


int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n], maxi = 0;
    rep(i, n) {
        cin >> a[i];
        maxch(maxi, a[i]);
    }

    string ans = "Impossible";
    if (n == 2 && a[0] == 1 && a[1] == 1) {
        ans = "Possible";
    } else if (n > 2 && maxi > 1) {
        int exist[n] = {};
        rep(i, n) {
            exist[a[i]]++;
        }
        bool ok = true;
        if (maxi % 2 == 0) {
            repl(i, maxi / 2, maxi + 1) {
                if (i == maxi / 2 && exist[i] != 1) ok = false;
                else if (i > maxi / 2 && exist[i] < 2) ok = false;
            }
            rep(i, maxi / 2) if (exist[i] > 0) ok = false;
        } else {
            repl(i, (maxi / 2) + 1, maxi + 1) {
                if (i == (maxi / 2) + 1 && exist[i] != 2) ok = false;
                if (i > (maxi / 2) + 1 && exist[i] < 2) ok = false;
            }
            rep(i, maxi / 2) if (exist[i] > 0) ok = false;
        }
        if (ok) ans = "Possible";
    }
    cout << ans << endl;
    return 0;
}