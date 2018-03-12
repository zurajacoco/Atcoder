#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define repr(i,a,b) for(int i=(int)(a-1);i>=b;i--)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout << #x" = " << x << endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define INF INT_MAX/3
#define MOD (ll)(1e9 + 7)

ll fact[100010];

void factorial() {
    fact[0] = 1;
    repl(i, 1, 100010) fact[i] = (i * fact[i - 1]) % MOD;
}

int main(){
    cin.sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    if (abs(n - m) > 1) {
        cout << 0 << endl;
    } else {
        factorial();
        if (n == m) cout << (((fact[n] * fact[m]) % MOD) * 2) % MOD << endl;
        else cout << (fact[n] * fact[m]) % MOD << endl;
    }
    return 0;
}