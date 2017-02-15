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
  string s;
  cin >> s;

  int ans = 0;
  if (s.length() > 1) {
    bool mul = false, zero = false;
    repl(i, 1, s.length()) {
      if(!mul && s[i] == '+' && s[i - 1] != '0') {
        ans++;
      } else if (!mul && s[i] == '*') {
        mul = true;
        zero = (s[i - 1] == '0') ? true : false;
      } else if (mul && s[i] == '*') {
        zero = (s[i - 1] == '0' || zero) ? true : false;
      } else if (mul && s[i] == '+') {
        ans += (zero || s[i - 1] == '0') ? 0 : 1;
        mul = zero = false;
      }
      i++;
    }

    if(s[s.length() - 2] == '+' && s[s.length() - 1] != '0') {
      ans++;
    } else if (mul && !zero && s[s.length() - 1] != '0') {
      ans++;
    }
  } else {
    ans = (s[0] == '0') ? 0 : 1;
  }

  print(ans);

  return 0;
}