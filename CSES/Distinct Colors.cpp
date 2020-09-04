#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;
const int INF = 1e9+5;

struct query {
    int l,r,id;

    bool operator< (const query &o) const {
        if (o.r == r) return l > o.l; // de mayor a menor por si tengo que registrar valor nuevo
        return r < o.r;
    }
};

vi G[MAXN];
query queries[3*MAXN];
int col[MAXN]; ii col2[MAXN];
int rta[MAXN], actT = 1, ind = 0;
int FT[2*MAXN], occur[MAXN];
bitset<MAXN> done;

void dfs (int st) { // Euler Tour
    done[st] = true;
    int tin = actT, tout = actT;
    queries[ind++] = {actT,actT,-col[st]}; actT++; // query de establecer

    for (auto &i : G[st])
        if (!done[i]) {
            dfs(i);
            queries[ind++] = {actT,actT,-col[st]}; // de establecer
            tout = actT++;
        }

    queries[ind++] = {tin,tout,st}; // query de preguntar
}

void compressColors (int n) {
    sort(col2,col2+n);
    int actC = 1; // empiezo en uno porque requiero colores al menos positivos
    col[col2[0].snd] = actC;
    forsn(i,1,n) {
        if (col2[i].fst != col2[i-1].fst) actC++;
        col[col2[i].snd] = actC;
    }
}

void setFT (int p, int v) {
    for (int i = p; i < 2*MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    int n; scanf("%d",&n);

    forn(i,n) {
        scanf("%d",&col[i]);
        col2[i] = {col[i],i};
    }
    forn(i,n-1) {
        int a,b; scanf("%d %d",&a,&b); a--; b--;
        G[a].pb(b); G[b].pb(a);
    }

    compressColors(n);
    dfs(0);
    sort(queries,queries+ind);

    forn(i,ind) {
        if (queries[i].id < 0) {
            if (occur[-queries[i].id]) setFT(occur[-queries[i].id],-1); // cancelo el viejo
            setFT(queries[i].l+1,1); // lo vuelvo de nuevo positivo y pongo el nuevo
            occur[-queries[i].id] = queries[i].l+1; // marco nueva posición
        }
        else rta[queries[i].id] = getFT(queries[i].r+1) - getFT(queries[i].l);
    }

    forn(i,n) printf("%d ",max(rta[i],1));

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
