#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF INT_MAX/3

#define MAX_N 1000
vector<string> v = {"dream", "dreamer", "erase", "eraser"};

int main(){
    cin.sync_with_stdio(false);
    string s;
    cin >> s;

    int i = s.size() - 1;
    bool ok = true;
    while (s.size() > 0) {
        string tmp1 = " ", tmp2 = " ";
        if (s[i] == 'r') {
            if (s.size() > 5) {
                tmp1 = s.substr(i - 5, 6);
            }
            if (s.size() > 6) {
                tmp2 = s.substr(i - 6, 7);
            }
            if (tmp1 == v[3]) {
                i -= 6;
                s = s.substr(0, i + 1);
            } else if (tmp2 == v[1]) {
                i -= 7;
                s = s.substr(0, i + 1);
            } else {
                ok = false;
                break;
            }
        } else if (s[i] == 'e') {
            if (s.size() > 4) {
                tmp1 = s.substr(i - 4, 5);
            }
            if (tmp1 == v[2]) {
                i -= 5;
                s = s.substr(0, i + 1);
            } else {
                ok = false;
                break;
            }
        } else if (s[i] == 'm') {
            if (s.size() > 4) {
                tmp1 = s.substr(i - 4, 5);
            }
            if (tmp1 == v[0]) {
                i -= 5;
                s = s.substr(0, i + 1);
            } else {
                ok = false;
                break;
            }
        } else {
            ok = false;
            break;
        }
    }

    cout << ((ok) ? "YES" : "NO") << endl;

    return 0;
}