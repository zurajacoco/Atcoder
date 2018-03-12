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

#define INF INT_MAX
#define MAX_N 1000000001


int main(){
  cin.sync_with_stdio(false);
  int n;
  cin >> n;

  int a = 1, b = 2, maximum = 0;
  repl(i, 2, n + 1) {
    int dist;
    cout << "? " << a << " " << i << endl;
    cin >> dist;
    if (maximum < dist) {
      maximum = dist;
      b = i;
    }
  }

  maximum = 0;
  repl(i, 1, n + 1) {
    if (i == b) continue;
    int dist;
    cout << "? " << b << " " << i << endl;
    cin >> dist;
    maxch(maximum, dist);
  }

  cout << "! " << maximum << endl;

  return 0;
}