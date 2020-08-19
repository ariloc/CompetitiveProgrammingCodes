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

const int MAXN = 66e3;
const int INF = 1e9+5;

struct margenes{
    int l,r,d,u;
};

vector<margenes> ptos;
int dp[MAXN], rta[MAXN];

int main() {
//    freopen("placas.in","r",stdin);
//    freopen("placas.out","w",stdout);

    int N,K;
    scanf("%d %d",&K,&N);

    forn (i,N) { // ingreso coords con sus respectivos márgenes
        int x,y;
        scanf("%d %d",&x,&y);
        ptos.push_back({x-K,x+K,y-K,y+K});
    }

    forsn (m,1,(1<<N)) { // para cada posibilidad de agrupar, calculo las vallas utilizadas
        int bL,bR,bU,bD; bL = bD = INF; bU = bR = 0;
        forn (i,N)
            if (m & (1<<i)) {
                bL = min(bL,ptos[i].l); bR = max(bR,ptos[i].r);
                bD = min(bD,ptos[i].d); bU = max(bU,ptos[i].u);
            }
        dp[m] = ((bR-bL)+(bU-bD))*2; // placas utilizadas para esta posibilidad
    }

    forsn (m,1,(1<<N)) {  // dadas todas las agrupaciones posibles
        rta[m] = INF;
        for (int sm = m; sm; sm=(sm-1)&m) { // voy sumando las agrupaciones con dp para obtener lo menos posible
            int calc = dp[sm] + rta[sm xor m];
            rta[m] = min(rta[m],calc);
        }
    }

    printf("%d",rta[(1<<N)-1]);

    return 0;
}
