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
    ll n, a;
    cin >> n;
    ll odd_sum = 0, even_sum = 0;
    ll odd_cost = 0, even_cost = 0;
    rep(i, n) {
        cin >> a;
        if (i % 2) { // odd
            if (odd_sum + a > 0) odd_sum += a;
            else {
                odd_cost += abs(1 - (odd_sum + a));
                odd_sum = 1;
            }

            if (even_sum + a < 0) even_sum += a;
            else {
                even_cost += abs(-1 - (even_sum + a));
                even_sum = -1;
            }
        } else {
            if (odd_sum + a < 0) odd_sum += a;
            else {
                odd_cost += abs(-1 - (odd_sum + a));
                odd_sum = -1;
            }

            if (even_sum + a > 0) even_sum += a;
            else {
                even_cost += abs(1 - (even_sum + a));
                even_sum = 1;
            }
        }
    }
    cout << min(odd_cost, even_cost) << endl;
    return 0;
}