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

map<int,int> fact (int x) {
    map<int,int> F;
    for (int j = 2; j*j <= x; j++)
        while (!(x%j)) F[j]++, x /= j;
    if (x > 1) F[x]++;
    return F;
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int x,d; scanf("%d %d",&x,&d);

        int cnt_pot = 0;
        while (!(x%d)) x /= d, cnt_pot++;

        map<int,int> myF = fact(x);

        if (cnt_pot <= 1) {puts("NO"); continue;} // beautiful
        else {
            int s = 0;
            for (auto &j : myF) s += j.snd;
            if (s > 1) puts("YES"); // si no puedo representar distinto por el que sobra, va por el d
            else if (cnt_pot <= 2) puts("NO");
            else {
                map<int,int> myF2 = fact(d);
                
                // Como hay al menos 2 factores, al distribuir a c/u le falta en el peor caso algun 
                // factor primo para dejar de ser bello. Como el num de afuera es primo (en myF) 
                // (o no existe, caso s == 0), en el caso que al multiplicar ese de afuera
                // pasara que un factor deja de ser bello, decido entonces ponerlo en el otro factor
                // (pues cnt_pot >= 3 en este punto) y no se rompe nada.
                // La distribución "heterogénea" de un factor a los otros, para representar distinto
                // hace que esto funcione, pero se rompa si son todos iguales, cuando myF2.size() <= 1.
                if (myF2.size() > 1) puts("YES");  
                else {
                    // si es primo o potencia de primo (p^k)

                    if (d == (*myF2.begin()).fst) puts("NO"); // d es primo, no puedo reorganizar
                    else {
                        // retomando lo de antes, si myF2.size() == 1, entonces me funciona si tengo mas
                        // de 4, ya que paso de 4 a tres factores, y 1 va con el numero de afuera. Si
                        // no hay número de afuera porque x = d^k, entonces tampoco me importa si
                        // cnt_pot == 3. Nuevamente, esto es porque al distribuir no me queda ninguno
                        // como el d original si tengo 3, asi que no puedo meter nunca el 
                        // (nro de afuera) * d.
                        if (cnt_pot >= 4 || !s) puts("YES");
                        else {
                            // en el caso de cnt_pot == 3, y el numero de afuera si me importa (!= 1)
                            // tengo que ver si al meter dicho numero de afuera, el factor sigue o no
                            // bello al distribuir lo mejor que puedo (me es indistinto cuál factor 
                            // porque son todos iguales, pues myF2.size() == 1). Si se rompe lo bello, 
                            // ahi ya no puedo hacer nada. "Lo mejor que puedo es darle" un factor primo 
                            // de la descomposición a uno, y todo el resto al otro. Si le diera todo a uno,
                            // queda un cuadrado y dejaría de ser bello. "Tengo que partirlo" sí o sí.
                            int p_base = (*myF2.begin()).fst;
                            ll v2 = d * (ll)(*myF.begin()).fst;

                            // puedo distribuir expK entre v2 y p_base tal que ambos sean beautiful?
                            v2 *= (ll)p_base;
                            int cnt_aux = 0;
                            while (!(v2%d)) cnt_aux++, v2 /= d;

                            if (cnt_aux > 1) puts("NO");
                            else puts("YES");
                        }
                    }
                }
            }
        }

    }

    return 0;
}