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

#define MAX_N 1001
#define mod 1000000007

void primeNumber();
void factorization(int[], int);

int prime[MAX_N] = {};

int main(){
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	int num[n + 1] = {};

	primeNumber();
	repl(i, 2, n + 1) {
		factorization(num, i);
	}

	ll ans = 1;
	rep(i, n + 1) {
		ans = (ans * (num[i] + 1)) % mod;
	}

	cout << ans << endl;

	return 0;
}

void primeNumber() {
	prime[1] = 1;
	repl(i, 2, MAX_N + 1) {
		if (prime[i] == 1) continue;
		int j = i * 2;
		while(j < MAX_N) {
			prime[j] = 1;
			j += i;
		}
	}
}

void factorization(int num[], int i) {
	int tmp = i;
	if (prime[i] != 0) {
		repl(i, 2, i + 1) {
			if (tmp == 1) break;
			if (tmp % i == 0) {
				tmp /= i;
				num[i]++;
				i--;
			}
		}
	} else {
		num[i]++;
	}
}