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

int main(){
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a = -1, b = -1, c = -1;
    if (n * 4 >= m) {
        if (m % 2 == 1) {
            b = 1;
            m -= 3;
            n--;
        } else {
            b = 0;
        }
        rep(i, n + 1) {
            if (i * 2 + (n - i) * 4 == m) {
                a = i, c = n - i;
                break;
            }
        }
        if (a == -1) b = -1;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}