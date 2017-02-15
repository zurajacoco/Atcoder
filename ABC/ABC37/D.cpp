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
typedef pair<ll, P> PLP;
typedef pair<P, ll> PPL;
typedef set<int> S;

#define INF INT_MAX/3
#define MAX_N 1000000001
#define MOD 1000000007

int main(){
	cin.sync_with_stdio(false);
	int h, w;
	cin >> h >> w;

	vector<PLP> v(h * w);
	ll map[h + 2][w + 2] = {};
	ll dp[h + 2][w + 2] = {};
	repl(i, 1, h + 1) {
		repl(j, 1, w + 1) {
			cin >> map[i][j];
			v.pb(PLP(map[i][j], P(i, j)));
		}
	}

	sort(v.begin(), v.end());

	int vx[] = {1, 0, -1, 0};
	int vy[] = {0, 1, 0, -1};
	rep(i, v.size()) {
		int y = v[i].se.fi, x = v[i].se.se;
		dp[y][x]++;
		rep(j, 4) {
			if(map[y][x] > map[y + vy[j]][x + vx[j]]){
				dp[y][x] += dp[y + vy[j]][x + vx[j]];
				dp[y][x] %= MOD;
			}
		}
	}

	ll ans = 0;
	repl(i, 1, h + 1) {
		repl(j, 1, w + 1) {
			ans += dp[i][j];
			ans %= MOD;
		}
	}
	print(ans);

	return 0;
}