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
#define MOD 1000000009

ll h, w;
int alpha[26];

int main(){
    cin.sync_with_stdio(false);
    cin >> h >> w;

    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            alpha[s[j] - 'a']++;
        }
    }

    char panel[h][w];
    if (h % 2 == 0 && w % 2 == 0) {
        bool ok = true;
        rep(i, 26) {
            if (alpha[i] % 4 != 0) ok = false;
        }
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else if (h % 2 == 0 && w % 2 == 1) {
        ll cnt = 0, odd = 0;
        rep(i, 26) {
            cnt += alpha[i] / 4;
            if (alpha[i] % 2 == 1) odd = 1;
        }
        if (odd == 0 && cnt >= h * (w - 1) / 4) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else if (h % 2 == 1 && w % 2 == 0) {
        ll cnt = 0, odd = 0;
        rep(i, 26) {
            cnt += alpha[i] / 4;
            if (alpha[i] % 2 == 1) odd = 1;
        }
        if (odd == 0 && cnt >= (h - 1) * w / 4) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        ll cnt = 0, odd = 0;
        rep(i, 26) {
            cnt += alpha[i] / 4;
            if (alpha[i] % 2 == 1) odd++;
        }
        if (odd == 1 && cnt >= (h - 1) * (w - 1) / 4) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}