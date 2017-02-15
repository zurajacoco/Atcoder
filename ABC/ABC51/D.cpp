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

int n, m;
int e[MAX_N][MAX_N];
int edge[MAX_N][MAX_N];

int main(){
	cin.sync_with_stdio(false);
	cin >> n >> m;

	rep(i, n + 1) {
		rep(j, n + 1) {
			edge[i][j] = (i == j) ? 0 : INF;
			e[i][j] = INF; 
		}
	}

	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a][b] = e[b][a] = edge[a][b] = edge[b][a] = c; 
	}

	repl(i, 1, n + 1) {
		repl(j, 1, n + 1) {
			repl(k, 1, n + 1) {
				minch(edge[j][k], edge[j][i] + edge[i][k]);
			}
		}
	}

	int cnt = 0;
	rep(i, n + 1) {
		rep(j, n + 1) {
			if (e[i][j] != INF && edge[i][j] == e[i][j]) cnt++;
		}
	}

	cout << m - cnt / 2 << endl;

	return 0;
}