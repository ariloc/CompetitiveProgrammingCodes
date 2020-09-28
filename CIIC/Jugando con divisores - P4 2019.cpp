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

const ll MOD = 1e6+3;
const int MAXN = 22;

int num[MAXN];
ll dp[1<<MAXN],D[MOD+5];

void cribaDiv (int N) {
    forsn(i,1,N) {
        ll toAdd = (ll)i*i;
        for (int j = i+i; j < N; j += i) D[j] += toAdd; // empiezo en i+i pues no me cuento
    }
}

int main() {
    cribaDiv(MOD+5);
    int n,q; scanf("%d %d",&n,&q);
    forn(i,n) scanf("%d",&num[i]);

    forsn(mk,1,(1<<n)) {
        ll prod = 1; // empieza en 1 porque incl. (1) pero excl. sí mismo
        forn(j,n) if (mk & (1<<j)) prod = (prod*num[j])%MOD;
        dp[mk] = D[prod];
    }

    forn(i,n) forn(mk,(1<<n))
        if (!(mk & (1<<i))) dp[mk] += dp[mk+(1<<i)];

    forn(i,q) {
        int ni; scanf("%d",&ni);
        int mk = 0;
        forn(j,ni) {
            int x; scanf("%d",&x);
            forn(k,n) if (x == num[k] and !(mk & (1<<k))) {mk |= (1<<k); break;} // tiene check si no marqué uno de igual valor
        }
        printf("%lld ",dp[mk]);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
