#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,n) for(int i=(int)(n-1);i>=1;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x"=" << x <<endl
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
	int n, a;
	cin >> n >> a;

	ll sum[2501][51] = {};
	rep(i, n) {
		int x;
		cin >> x;
		repr(j, 2501) {
			if (j + x > 2500) continue;
			repl(k, 1, 51) {
				if (sum[j][k] > 0) {
					sum[j + x][k + 1] += sum[j][k];
				}
				if (k == 1 && j == x) {
					sum[j][k]++;
				}
			}
		}
	}

		ll  cnt = 0;
		repl(i, 1, n + 1) {
			int tmp = i * a;
			cnt += sum[tmp][i];
		}

		cout << cnt << endl;

		return 0;
	}