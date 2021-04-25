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

const int MAXN = 20;
const int MAXD = 10;

ll dp[MAXD][2][2][2]; // usando este dígito, alternando 0,1, si ya soy menor al num, si tengo un dígito positivo o no

ll solve (ll x) {
    if (!x) return 1;
    vi dig;
    while (x) dig.pb(x%10), x /= 10;

    forn(i,MAXD) forn(j,2) forn(k,2) dp[i][0][j][k] = 0; // reset
    forsn(i,1,dig.back()) dp[i][0][1][1] = 1;
    dp[0][0][1][0] = 1; // el cero siempre será menor al primer dígito, entonces lo cuento
    dp[dig.back()][0][0][1] = 1; // siempre el primer dígito será mayor a cero

    int prv = dig.back();
    dig.pop_back(); bool act = 1;
    while (!dig.empty()) {
        forn(i,MAXD) forn(j,2) forn(k,2) dp[i][act][j][k] = 0; // reset

        forn(i,MAXD) forn(j,MAXD) if (i != j) dp[j][act][1][1] += dp[i][!act][1][1]; // los comunes
        forsn(j,1,MAXD) dp[j][act][1][1] += dp[0][!act][1][0]; // cuando se vuelve un número posta
        dp[0][act][1][0] += dp[0][!act][1][0]; // siempre menor por lo de antes

        forn(i,dig.back()) if (i != prv) dp[i][act][1][1] += dp[prv][!act][0][1]; // si viene del núm og, entonces pasó por un positivo
        if (dig.back() != prv) dp[dig.back()][act][0][1] += dp[prv][!act][0][1];
        prv = dig.back(); dig.pop_back(); act = !act;
    }

    ll s = 0;
    forn(j,MAXD) s += dp[j][!act][0][1] + dp[j][!act][1][1];

    return s+1; // siempre cuento el cero
}

int main() {
    ll l,r; scanf("%lld %lld",&l,&r);

    printf("%lld",solve(r)-(l-1 < 0 ? 0 : solve(l-1)));

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
