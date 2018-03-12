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

#define INF LONG_MAX/3

int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    ll a[3 * n] = {};
    ll sumf[n + 1] = {}, sumb[n + 1] = {};
    priority_queue<ll, vector<ll>, greater<ll>> front;
    priority_queue<ll> back;
    rep(i, 3 * n) {
        cin >> a[i];
        if (i < n) {
            front.push(a[i]);
            sumf[0] += a[i];
        } else if (i > 2 * n - 1) {
            back.push(a[i]);
            sumb[0] += a[i];
        }
    }

    repl(i, n, 2 * n) {
        sumf[i - n + 1] = sumf[i - n] + a[i];
        front.push(a[i]);
        ll t = front.top(); front.pop();
        sumf[i - n + 1] -= t;
    }

    repr(i, 2 * n, n) {
        sumb[2 * n - i] = sumb[2 * n - 1 - i] + a[i];
        back.push(a[i]);
        ll t = back.top(); back.pop();
        sumb[2 * n - i] -= t;
    }

    ll ans = -INF;
    rep(i, n + 1) maxch(ans, sumf[i] - sumb[n - i]);
    cout << ans << endl;
    return 0;
}