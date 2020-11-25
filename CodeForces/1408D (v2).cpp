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

const int MAXN = 2002;
const int MAXMOV = 1e6+5; // max movimientos en una coordenada (por cotas)
const int INF = 1e9;

ii rob[MAXN], lights[MAXN];
int dp[MAXMOV];

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%d %d",&rob[i].fst,&rob[i].snd);
    forn(i,m) scanf("%d %d",&lights[i].fst,&lights[i].snd);
    sort(lights,lights+m);

    forn(i,n) forn(j,m)
        if (rob[i].fst <= lights[j].fst && rob[i].snd <= lights[j].snd)
            dp[lights[j].fst-rob[i].fst] = max(dp[lights[j].fst-rob[i].fst],lights[j].snd-rob[i].snd+1);
    /* si yo uso una cantidad de movimientos tal que el ladrón i se queda a la izquierda (coord x menor o igual)
       del radar j, entonces para estar fuera del mapa se le suma al menos la diferencia de coords en y,
       +1 (para pasarlo) */

    /* Aprovechando que el área de detección de los radares es infinito hacia x e y menores, implica que al área
       efectiva que estoy cubriendo, en cuanto a la altura en una determinada x, como mucho disminuye (o se
       mantiene igual). En consecuencia, si veo para todos los puntos, no me van a afectar las alturas de
       probar más movs a la derecha, porque la altura solo tiende a aumentar si lo recorro de más a menos en x
       (por lo que la altura de lo cubierto menor o igual en mayor coord x). Así nomás puedo probar para todos
       los movs a la derecha, qué altura debería tener mínimo para que todos los ladrones estén fuera de los
       radares, y conseguir el mínimo.*/

    int mini = INF;
    dforn(i,MAXMOV) {
        dp[i] = max(dp[i],dp[i+1]);
        mini = min(mini,i+dp[i]);
    }

    printf("%d",mini);


    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
