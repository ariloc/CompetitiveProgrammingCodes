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

int query (int a, int b, int c) {
    printf("%d %d %d\n",a,b,c); fflush(stdout);
    int aux; scanf("%d",&aux);
    return aux;
}

int main() {
    int t,n,q; scanf("%d %d %d",&t,&n,&q);

    forn(o,t) {
        vi rta;

        int m = query(1,2,3)-1;
        rta.pb((m+2)%3+1); rta.pb(m+1); rta.pb((m+1)%3+1);

        // fuerzo lo random de mis queries para romper el caso que siempre el número esté fuera de mi rango y tenga que hacer la query del final
        // (no funciona si el interactor es adaptive, adaptativo)
        vi queryNum; forsn(i,4,n+1) queryNum.pb(i);
        random_shuffle(all(queryNum));

        forn(j,queryNum.size()) {
            int i = queryNum[j];

            int l = 0, r = (int)rta.size()-1;
            while (r-l > 1) {
                int lr = (2*l+r)/3, rl = (l+2*r)/3;

                int v = query(rta[lr],i,rta[rl]);

                if (v == i) l = lr, r = rl;
                else if (v == rta[lr]) r = lr;
                else l = rl;
            }
            
            if (!l || r == (int)rta.size()-1) { // sólo sospecho en los bordes, y probabilísticamente es un win (sumado al random_shuffle)
                int v = query(i,rta[l],rta[r+(r==l)]);
                if (v == i) rta.insert(rta.begin()+l+1,i);
                else if (v == rta[l]) rta.insert(rta.begin()+l,i);
                else rta.insert(rta.begin()+r+1,i);
            } else rta.insert(rta.begin()+l+1,i);
        }

        forn(i,n) printf("%d ",rta[i]);
        printf("\n"); fflush(stdout);
        int tmp; scanf("%d",&tmp);
        if (tmp != 1) return 0;
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
