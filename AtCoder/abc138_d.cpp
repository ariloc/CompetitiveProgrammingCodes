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
typedef long double ld;

const int MAXN = 2e5+5;

vi G[MAXN];
ll cnt[MAXN];
bitset<MAXN> done;

void dfs (int st, ll acc = 0) {
    done[st] = true;
    cnt[st] += acc;
    acc = cnt[st];
    for (auto &i : G[st])
        if (!done[i])
            dfs(i,acc);
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    forn(i,n-1) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    forn(i,q) {
        int p,x; scanf("%d %d",&p,&x); p--;
        cnt[p] += x;
    }

    dfs(0);

    forn(i,n) printf("%lld ",cnt[i]);
    
    return 0;
}