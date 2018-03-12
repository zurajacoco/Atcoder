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

int main(){
    cin.sync_with_stdio(false);
    int n, i = 0;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    ll ans = 1, kind = -1;
    while(i < n) {
        if (i < n - 1 && s1[i] == s1[i + 1]) {
            if (kind == -1) ans = (ans * 6) % MOD;
            else if (kind == 0) ans = (ans * 2) % MOD;
            else ans = (ans * 3) % MOD;
            kind = 1;
            i++;
        } else {
            if (kind == -1) ans = (ans * 3) % MOD;
            else if (kind == 0) ans = (ans * 2) % MOD;
            else ans = (ans * 1) % MOD;
            kind = 0;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}