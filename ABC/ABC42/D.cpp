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
#define MOD 1000000007

void factrial();
ll factInv(ll);

ll fact[200001];

int main(){
	cin.sync_with_stdio(false);
	ll h, w, a, b;
	cin >> h >> w >> a >> b;

	factrial();

	ll all = fact[h + w - 2] * factInv(fact[w - 1] * fact[h - 1]) % MOD;
	ll out = 0;
	rep(i, b) {
		out = (out + (((fact[h - a - 1 + i] * factInv(fact[h - a - 1] * fact[i])) % MOD)
			* ((fact[a + w - i - 2] * factInv(fact[a - 1] * fact[w - i - 1])) % MOD))) % MOD;
	}
	ll ans = (all - out) % MOD;
	if (ans < 0) ans = MOD + ans;

	cout << ans << endl;

	return 0;
}

void factrial(){
	fact[0] = 1;
	fact[1] = 1;
	repl(i, 2, 200001) {
		fact[i] = fact[i - 1] * i % MOD;
	}
}

ll factInv(ll x){
	x %= MOD;
	ll res = 1;
	ll n = MOD - 2;
	while (n > 0) {
		if (n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}