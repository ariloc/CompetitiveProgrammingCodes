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

const int MAXN = 205;

bool mat[MAXN][MAXN];

int main() {
    freopen("grafoscuriosos10.txt","r",stdin);
    freopen("output_grafoscuriosos10.txt","w",stdout);
    int t; scanf("%d",&t);

    forn(o,t) {
        int n; scanf("%d",&n);
        int rest = n%4;
        if (!rest || rest == 1) {
            forn(i,n) forn(j,n) mat[i][j] = 0; // reset, por las dudas

            n -= rest;
            for (int j = 0; j < n; j += 2) // sólo conectados los de resto 0 y resto 2 (dos cliques)
                for (int k = j%4; k < n; k += 4) // representa una cuarta parte de los nodos
                    if (k != j) mat[j][k] = 1;

            // conecto las de resto 0 con las de resto 2, así las cliques quedan al lado en la tira
            for (int j = 0; j < n; j += 4) 
                for (int k = 2; k < n; k += 4)
                    mat[j][k] = mat[k][j] = 1;

            // conecto los extremos: resto 1 con las de resto 0, resto 3 con las de resto 2
            for (int j = 1; j < n; j += 4) 
                for (int k = 0; k < n; k += 4)
                    mat[j][k] = mat[k][j] = 1;
            for (int j = 3; j < n; j += 4) 
                for (int k = 2; k < n; k += 4)
                    mat[j][k] = mat[k][j] = 1;

            if (rest) // si me queda uno flotando, lo meto
                for (int j = 0; j < n; j += 2) mat[j][n] = mat[n][j] = 1; // los conecto con los de cliques, y es n porque antes hice - rest

            puts("1");
            for (int j = 0; j < n; j += 4) printf("%d %d %d %d ",j+3,j,j+1,j+2);
            if (rest) printf("%d ",n);
            putchar('\n');
            forn(i,n+rest) {
                forn(j,n+rest) printf("%d",(int)mat[i][j]);
                putchar('\n');
            }
        }
        else puts("0");
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
