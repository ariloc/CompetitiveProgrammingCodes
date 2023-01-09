#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 2e5+5;
const int INF = 1e9;

int mono[MAXN], poly[MAXN];
int dp[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);
        forn(i,n) scanf("%d",&mono[i]);
        forn(i,n) scanf("%d",&poly[i]);

        forn(i,n+1) dp[i] = 0;

        vi ord;
        forn(i,n) if (mono[i] > poly[i]) ord.pb(-poly[i]), ord.pb(mono[i]);
        sort(all(ord), [](const int &lhs, const int &rhs) { return abs(lhs) < abs(rhs); });

        int sz = (int)ord.size();
        forn(i,sz) dp[i] = ord[i] < 0 ? -1 : 1, ord[i] = abs(ord[i]);
        forsn(i,1,sz) dp[i] += dp[i-1];

        vi rta;
        forsn(i,1,n+1) {
            bool posib = true;
            for (int j = i; j <= n; j += i) {
                int indr = upper_bound(all(ord),j)-ord.begin()-1;
                int indl = upper_bound(all(ord),j-i)-ord.begin();
                //cerr << s << ' ' << indl << ' ' << indr << ' ' << j << ' ' << i << "OKK" << endl;
                if (indr >= 0 && indl >= 0) { 
                    int s = dp[indr]-(indl-1 < 0 ? 0 : dp[indl-1]);
                    // cerr << s << ' ' << indl << ' ' << indr  << ' ' << j << ' ' << i << endl; 
                    if (s != 0) { posib = false; break; }
                }
            }
            if (posib) rta.pb(i);
        }

        printf("%d\n",(int)rta.size());
        for (auto &i : rta) printf("%d ", i);
        puts("");
    }
   
    return 0;
}
