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
#define MOD 10007

ll tri[1000001];

void trib() {
    tri[1] = 0;
    tri[2] = 0;
    tri[3] = 1;
    repl(j, 4, 1000001) tri[j] = ((tri[j - 1] + tri[j - 2]) % MOD + tri[j - 3]) % MOD;
}

int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    trib();
    cout << tri[n] << endl;
    return 0;
}