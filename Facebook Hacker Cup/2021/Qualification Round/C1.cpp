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

const int MAXN = 52;

ll gold[MAXN];
vi G[MAXN];
bitset<MAXN> done;
pair<ll,ll> maxi[MAXN];

ll dfs (int st, ll sum) {
    done[st] = true;

    ll max1 = 0, max2 = 0;
    for (auto &i : G[st])
        if (!done[i]) {
            ll aux = dfs(i, sum + gold[st]);
            if (aux >= max1) swap(max1,max2), max1 = aux;
            else if (aux > max2) max2 = aux;
        }

    maxi[st] = {max1,max2};

    return max(max1, sum + gold[st]);
}

int main() {
    freopen("output.txt","w",stdout);

    int t; scanf("%d",&t);
    forn(o,t) {
        int n; scanf("%d",&n);

        forn(i,n) G[i].clear(), maxi[i] = {0,0}; // reset
        done.reset();

        forn(i,n) scanf("%lld",&gold[i]);

        forn(i,n-1) {
            int u,v; scanf("%d %d",&u,&v); u--, v--;
            G[u].pb(v), G[v].pb(u);
        }

        ll aux_rt = gold[0]; // me saco la cueva que paso dos veces para no contar de más
        gold[0] = 0;
        dfs(0,0);

        printf("Case #%d: %lld\n",o+1,maxi[0].fst + maxi[0].snd + aux_rt);
    }

    return 0;
}