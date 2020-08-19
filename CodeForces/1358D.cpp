#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(ll i = ll(s); i < ll(n); i++)
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

/* Consideremos que es ideal ponerlo al final del mes. Si lo corremos el rango a la derecha puede pasar:
    - Sube 1 a la izquierda, nada a la derecha -> sube valor
    - Sube 1 a la izquierda y baja 1 a la derecha -> valor igual
    - Sube 1 a la izquierda y baja >1 a la derecha -> empeora

    los casos donde baja a la izquierda es todo pérdida, así que están descartados
    El primer caso que es el único que me convendría ir al principio...pasa cuando tengo dos meses
    de 1 día, y eso sería entonces también el final del otro mes. Por lo que realmente
    volvemos a la misma situación, y se gana.

    Entonces siempre gano teniendo el último día al final de un mes.
*/

const int MAXN = 4e5+20;

ll dp[MAXN], days[MAXN];

int main() {
    FAST_IO;

    ll n,x; cin >> n >> x;
    forn (i,n) {
        cin >> days[i]; days[i+n] = days[i];
        dp[i] = dp[i+n] = (((ll)days[i]*(days[i]+1))/(ll)2); // calcular total abrazos
    }
    n *= 2;

    ll maxi = 1, i = n-1, sum = 0, cnt = 0;
    dforn (j,n) {
        while (i >= 0 and cnt < x) {
            sum += dp[i]; cnt += days[i];
            i--;
        }

        ll calc,tmp;
        if (cnt == x) {maxi = max(sum,maxi); goto FIN;}
        calc = sum - dp[i+1];
        tmp = days[i+1]-(x-(cnt-days[i+1]));
        if (tmp < 0) goto FIN;
        calc += dp[i+1]-(((ll)tmp*(tmp+1))/2LL);
        if (calc > maxi) maxi = calc;

        FIN:
        sum -= dp[j]; cnt -= days[j];
    }

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!