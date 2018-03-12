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

string to_eight(string s) {
    string ret = "";
    string change = "0123345677";
    rep(i, s.size()) {
        if (s[i] == '4' || s[i] == '9') {
            ret += change[s[i++] - '0'];
            while(i++ < s.size()) ret += '7';
        } else {
            ret += change[s[i] - '0'];
        }
    }
    return ret;
}

ll to_ten(string s) {
    ll ret = 0;
    rep(i, s.size()) ret = ret * 8 + (s[i] - '0');
    return ret;
}

int main(){
    cin.sync_with_stdio(false);
    string a, b, c, d;
    cin >> a >> b;
    c = to_eight(a);
    d = to_eight(b);
    bool out = false;
    rep(i, a.size()) if (a[i] == '4' || a[i] == '9') out = true;
    cout << (stoll(b) - to_ten(d)) - (stoll(a) - to_ten(c)) + out << endl;
    return 0;
}