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

bool prime[100010];
int like[100010];

void is_prime() {
    rep(i, 100010) prime[i] = true;
    prime[0] = prime[1] = false;
    repl(i, 2, 100010) {
        if (!prime[i]) continue;
        int j = i + i;
        while(j < 100010) {
            prime[j] = false;
            j += i;
        }
    }
}

bool is_like() {
    memset(like, 0, sizeof(like));
    repl(i, 1, 100010) {
        if (i % 2 == 0) continue;
        int n = i, m = (i + 1) / 2;
        if (prime[n] && prime[m]) like[i] = 1;
    }
    repl(i, 1, 100010) like[i] += like[i - 1];
}

int main(){
    cin.sync_with_stdio(false);
    is_prime();
    is_like();
    int q;
    cin >> q;
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << like[r] - like[l - 1] << endl;
    }
    return 0;
}