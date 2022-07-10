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

int main() {
    int mo,n; ld pay,owe;
    while (scanf("%d %Lf %Lf %d",&mo,&pay,&owe,&n) != EOF) {
        if (mo < 0) break;

        int actMo = 0; ld val = pay+owe, prvPer = 1;
        ld cuota = owe/mo;
        int rta = -1;
        forn(i,n+1) { // 1+ dummy
            int x = mo+1; ld per;
            if (i < n) scanf("%d %Lf",&x,&per);
            while (actMo < x) {
                val *= (1-prvPer); if (actMo > 0) owe -= cuota;
                if (owe < val && rta == -1) rta = actMo;
                actMo++;
            }
            prvPer = per;
        }

        printf("%d month%s\n",rta,(rta != 1 ? "s" : ""));
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
