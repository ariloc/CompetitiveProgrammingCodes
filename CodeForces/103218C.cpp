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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 1e5+5;

vi G[MAXN];
int deg[MAXN];
bitset<MAXN> done;

bool dfs (int st, int canUse) {
    done[st] = true;

    vi children;
    for (auto &i : G[st])
        if (!done[i]) children.pb(i);

    if (canUse == 1) return true;

    if (children.empty()) 
        return false;
    
    if ((int)children.size() < 2)
        return dfs(children[0],canUse-1);

    if (canUse & 1) canUse--;
    return dfs(children[0],canUse/2) & dfs(children[1], canUse/2);
    
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n; scanf("%d",&n);

        forn(i,n) G[i].clear(), deg[i] = 0;

        forn(i,n-1) {
            int u,v; scanf("%d %d",&u,&v);
            G[u].pb(v), G[v].pb(u);
            deg[u]++, deg[v]++;
        }
        int low = 1, high = n+1;
        while (high-low > 1) {
            int mid = (high+low)/2;
            if (dfs(0,mid)) low = mid;
            else high = mid;
            forn(i,n) done[i] = 0;
        }
        
        printf("%d\n",low);
    }

    return 0;
}
