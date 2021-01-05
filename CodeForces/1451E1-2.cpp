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

const int MAXN = (1<<16);
const int INF = 1e9+5;

int xors[MAXN],pos[MAXN],rta[MAXN];

int main() {
    int n; scanf("%d",&n);

    set<int> prevXORS;
    ii rep = {-1,-1}; // if repeats exist
    forsn(j,1,n) {
        printf("XOR 1 %d\n",j+1);
        fflush(stdout);
        scanf("%d",&xors[j]);

        if (rep.fst == -1) {
            if (prevXORS.count(xors[j])) rep = {pos[xors[j]],j};
            if (!xors[j]) rep = {0,j};
        }
        pos[xors[j]] = j;
        prevXORS.insert(xors[j]);
    }

    if (rep.fst != -1) {
        printf("AND %d %d\n",rep.fst+1,rep.snd+1);
        fflush(stdout);
        int aux; scanf("%d",&aux);
        forn(j,n) rta[j] = xors[j]^xors[rep.fst]^aux;
    }
    else {
        // buscamos el más cercano al primero, por elegir uno arbitrario
        int mini = INF, ind = -1;
        forsn(j,1,n) if (xors[j] < mini) mini = xors[j], ind = j;

        printf("AND 1 %d\n",ind+1);
        fflush(stdout);
        int aux; scanf("%d",&aux);

        // nomás me queda decidir ahora si el número arbitrario elegido tiene el 1 al final o no
        // en consecuencia buscamos uno cuyo xor en dicho bit sea igual, y hacemos AND
        int ind2 = -1;
        forsn(j,1,n) if (!(xors[j]&1)) {ind2 = j; break;}
        printf("AND 1 %d\n",ind2+1);
        fflush(stdout);
        int aux2; scanf("%d",&aux2);

        aux |= (aux2&1); // le metemos el bit faltante

        forn(j,n) rta[j] = xors[j]^aux;
    }

    printf("! ");
    forn(j,n) printf("%d ",rta[j]);
    fflush(stdout);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
