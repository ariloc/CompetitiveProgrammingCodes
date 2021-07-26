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
const int MAXK = 30;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
const int NEUT = (1<<30)-1;

struct mon {
    int v;

    mon operator+ (const mon &o) const {
        return {v & o.v};
    }
};

struct queryTyp {
    int l,r,q;
};

int arr[MAXN];
int dp[MAXN][MAXK], acc[MAXK];
int rta[MAXN],N;
queryTyp queries[MAXN];
mon ST[2*MAXST];

void update (int p, int v) {
    p += N; ST[p].v = v;
    while (p > 1) {
        p /= 2;
        ST[p] = ST[2*p+1] + ST[2*p];
    }
}

mon query (int i, int tl, int tr, int bl, int br) {
    if (tl >= br || tr <= bl) return {NEUT};
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,tl,mid,bl,br) + query(2*i+1,mid,tr,bl,br);
}

int main() {
    int n,m; scanf("%d %d",&n,&m);
    
    N = (1<<(32-__builtin_clz(n)));

    forn(i,m) {
        int l,r,q; scanf("%d %d %d",&l,&r,&q);
        queries[i] = {l,r,q};

        forn(j,MAXK) 
            if (q&(1<<j)) dp[l][j]++, dp[r+1][j]--;

    }

    forsn(i,1,n+1) forn(j,MAXK) dp[i][j] += dp[i-1][j];
    forsn(i,1,n+1) forn(j,MAXK) ST[i-1+N].v |= (dp[i][j] > 0)*(1<<j);
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    bool posib = true;
    forn(i,m) {
        queryTyp x = queries[i];

        mon val = query(1,0,N,x.l-1,x.r);
        if (val.v != x.q) {posib = false; break;}
    }

    if (posib) {
        printf("YES\n");
        forn(i,n) printf("%d ",ST[i+N].v);
    }
    else printf("NO");

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!