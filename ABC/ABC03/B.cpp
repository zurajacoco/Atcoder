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

char at[] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

int main(){
    cin.sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    bool ok = true;
    rep(i, s.size()) {
        if (s[i] == t[i]) continue;
        if (s[i] == '@') {
            bool f = false;
            rep(j, 7) if (at[j] == t[i]) f = true;
            if (!f) ok = false;
        } else if (t[i] == '@') {
            bool f = false;
            rep(j, 7) if (at[j] == s[i]) f = true;
            if (!f) ok = false;
        } else {
            ok = false;
        }
    }
    if (ok) cout << "You can win" << endl;
    else cout << "You will lose" << endl;
    return 0;
}