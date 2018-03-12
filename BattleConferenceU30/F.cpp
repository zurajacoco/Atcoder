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
#define MAX_N 100001
#define MOD ((ll)1e9 + 7)

ll two[MAX_N];

void bekitwo(int n) {
  two[0] = 1;
  repl(i, 1, n) {
    two[i] = two[i - 1] * 2 % MOD;
  }
}


int main(){
  cin.sync_with_stdio(false);
  int n;
  cin >> n;

  bekitwo(n);
  ll sum[n + 1] = {};
  ll sumsum[n + 1] = {};
  ll kake[n + 1] = {};

  repl(i, 1, n + 1) {
    ll a;
    cin >> a;

    if (i > 1) {
      sum[i] = (sum[i - 1] + two[i - 2] * a + sumsum[i - 2] + kake[i - 1] * a) % MOD;
      kake[i] = (kake[i - 1] * a + a * two[i - 2]) % MOD;
    } else {
      sum[i] = a;
      kake[i] = a;
    }
    sumsum[i] = (sumsum[i - 1] + sum[i]) % MOD;
  }

  print(sum[n]);

  return 0;
}