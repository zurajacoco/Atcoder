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
#define MAX_N 1000000000000001

string s;
ll a, k;
ll ans = MAX_N;

void dfs(int i, ll num, set<int> st, int flag) {
    if (st.size() == 1 && st.count(0)) st.clear();
    if (i == s.size()) {
        minch(ans, abs(num - a));
    } else if (st.size() == k - 1){
        int y = s[i] - '0', x = (y + 9) % 10, z = (y + 1) % 10;
        bool f;
        f = st.count(x);
        st.insert(x);
        dfs(i + 1, num * 10 + x, st, 0);
        if (!f) st.erase(x);
        f = st.count(y);
        st.insert(y);
        dfs(i + 1, num * 10 + y, st, 0);
        if (!f) st.erase(y);
        st.insert(z);
        dfs(i + 1, num * 10 + z, st, 0);
    } else {
        if (flag == -1) dfs(i + 1, num * 10 + *max_element(st.begin(), st.end()), st, flag);
        else if (flag == 1) dfs(i + 1, num * 10 + *min_element(st.begin(), st.end()), st, flag);
        else {
            if (st.count(s[i] - '0') == 1) {
                dfs(i + 1, num * 10 + (s[i] - '0'), st, flag);
            } else {
                auto itr = lower_bound(st.begin(), st.end(), s[i] - '0');
                if (itr == st.end()) {
                    itr--;
                    dfs(i + 1, num * 10 + *itr, st, -1);
                } else if (itr == st.begin()) {
                    dfs(i + 1, num * 10 + *itr, st, 1);
                } else {
                    dfs(i + 1, num * 10 + *itr, st, 1);
                    itr--;
                    dfs(i + 1, num * 10 + *itr, st, -1);
                }
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin >> s >> k;
    a = stoll(s);

    set<int> st;
    int i = 0, j = -1;
    while(st.size() <= k && i < s.size()) {
        st.insert(s[i] - '0');
        if (st.size() == k - 1) j = i;
        i++;
    }

    if (st.size() <= k && i == s.size()) {
        cout << 0 << endl;
    } else if (a <= 100000) {
        ll x = -MAX_N, y = MAX_N;
        repr(i, a) {
            st.clear();
            string tmp = to_string(i);
            rep(j, tmp.size()) st.insert(tmp[j] - '0');
            if (st.size() <= k) {
                x = i;
                break;
            }
        }
        repl(i, a, 1000000) {
            st.clear();
            string tmp = to_string(i);
            rep(j, tmp.size()) st.insert(tmp[j] - '0');
            if (st.size() <= k) {
                y = i;
                break;
            }
        }
        cout << min(a - x, y - a) << endl;
    } else {
        ll num = 0;
        st.clear();
        rep(i, j + 1) num = num * 10 + (s[i] - '0'), st.insert(s[i] - '0');
        dfs(j + 1, num, st, 0);
        cout << ans << endl;
    }

    return 0;
}