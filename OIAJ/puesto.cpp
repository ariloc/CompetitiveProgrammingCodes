#include <bits/stdc++.h>

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

const int MAXN = 3e5+5;
const int MAXM = 8e4+2;
const int INF = 2e9+2;

struct nodo {
    int v,w;
};

struct edge {
    int a,b,l;
};

vector<nodo> G[MAXN];
pair<ii,ii> maxDist[MAXN];
bitset<MAXN> done,done2,done3;
int mini = INF, which = -1;
int maxNodo[MAXN], distToMax[MAXN];
edge edges[MAXM];
int segExtremo = -1;
ii got = {0,0};

int dfs (int &st) {
    done[st] = true;

    ii max1 = {0,-1}, max2 = {0,-1};
    for (auto &i : G[st])
        if (!done[i.v]) {
            int val = dfs(i.v)+i.w;
            if (val > max1.fst) {swap(max1,max2); max1 = {val,i.v};}
            else if (val > max2.fst) max2 = {val,i.v};
        }

    maxDist[st] = {max1,max2}; // conservo dos mayores distancias por nodo

    return max1.fst;
}

void dfs2 (int &st, int maxi) {
    done2[st] = true;

    maxNodo[st] = max(maxNodo[st],maxi);
    int calc = max(maxNodo[st],maxDist[st].fst.fst); // mi peor distancia a un nodo? acumulado de antes o subárbol?
    if (calc < mini)
        {mini = calc; which = st;} // guardo el de menor, mayor distancia a un nodo

    for (auto &i : G[st]) {
        if (!done2[i.v]) {
            int toPass = maxDist[st].fst.fst;
            if (maxDist[st].fst.snd == i.v) toPass = maxDist[st].snd.fst;
            toPass = max(toPass,maxNodo[st]); // obtengo el mayor o acumulado, o de subárbol
            dfs2(i.v,toPass+i.w);
        }
    }
}

int dfs3(int &st, int acc) {
    done3[st] = true;
    distToMax[st] = acc; // guardo dist a orig nodo

    int maxiD1 = 0, maxiD2 = 0, aristaD1 = -1;
    for (auto &i : G[st])
        if (!done3[i.v]) {
            int val = dfs3(i.v,acc+i.w);
            if (val+i.w > maxiD1) {swap(maxiD1,maxiD2); maxiD1 = val+i.w; aristaD1 = i.v;}
            else if (val+i.w > maxiD2) maxiD2 = val+i.w; // conservo dos mayores de distintas aristas
        }

    // lo siguiente lo hace última vez en origen, quedando justo de ese que quiero
    segExtremo = aristaD1;
    got = {maxiD1,maxiD2};
    return maxiD1;
}

int main() {
    freopen("puesto.in","r",stdin);
    freopen("puesto.out","w",stdout);

    int M; scanf("%d",&M);

    forn (i,M) {
        int a,b,l; scanf("%d %d %d",&a,&b,&l);
        a--; b--;
        G[a].pb({b,l});
        G[b].pb({a,l});
        edges[i] = {a,b,l};
    }

    int st = 0;
    dfs(st);
    dfs2(st,0);
    dfs3(which,0);
    // si resulta que el puesto queda en un nodo, no debe haber arista sin sentido específico
    if (got.fst == got.snd) segExtremo = -1;

    // correré la galería del nodo tal que esté balanceado entre mis dos nodos más lejanos
    printf("%.1f\n",((float)got.fst+got.snd)/2);

    ii edgeGal = {which,segExtremo};
    if (edgeGal.fst > edgeGal.snd) swap(edgeGal.fst,edgeGal.snd);
    forn (i,M) {
        if (min(edges[i].a,edges[i].b) == edgeGal.fst and max(edges[i].a,edges[i].b) == edgeGal.snd)
            {printf("0"); continue;} // si es la arista donde lo puse, no hay dirección específica
        if (distToMax[edges[i].a] > distToMax[edges[i].b]) printf("+");
        else printf("-");
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
