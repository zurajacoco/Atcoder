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

ll solve(ll, ll);

int main(){
	cin.sync_with_stdio(false);
	ll n , s;
	cin >> n >> s;

	cout << solve(n, s) << endl;

	return 0;
}

ll solve(ll n, ll s) {
	if (n == s) return n + 1;

	ll root = pow(n, 1.0/2);

	repl(i, 2, root + 1) {
		ll sum = 0, div = n;
		while(true) {
			sum += div % i;
			div /= i;
			if (div == 0) break;
		}
		if (sum == s) return i;
	}

	repr(i, root + 1) {
		ll b = (n - s) / i + 1;
		if (b < 2) break;
		ll sum = 0, div = n;
		while(true) {
			sum += div % b;
			div /= b;
			if (div == 0) break;
		}
		if (sum == s) return b;
	}

	return -1;
}
