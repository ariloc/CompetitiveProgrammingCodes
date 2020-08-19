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

/* Dado dos arrays de números A y B, determinar la mínima cantidad de operaciones
   que puedo realizar en el array B tal que MCM(A) = MCM(B). Defino a una operación
   como reemplazar el número en cierta posición del array B por cualquier otro entero
   positivo */

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

class DevuAndEqualizingLCM
{
    public:
    map<ll,int> F1,F2;
    void factPrim(ll n, map<ll,int> &F, bool mode){ // factorización en primos
        F.clear();
        for (ll p = 2; p*p <= n; p++)
            while (!(n%p)) {if (mode) F[p]++; else F[p]--; n/=p;}
        if (n > 1) if (mode) F[n]++; else F[n]--;
    }
    int minimumOperationsNeeded(vector<long long> A, vector<long long> B) {
        ll dcm = A[0];
        forn (i,1,A.size()) { // obtengo gcd de A
            dcm = __gcd(A[i],dcm);
            factPrim(A[i],F1);
        }

        // factorizo B, y considero aquellos que los reemplazo por gcd(a)
        // porque quiero que gcd(a) = gcd(b) ya que lcm(A) = (a_0 * a_1 * a_2 * ...a_n)/gcd(A);
        // lo más chico que puedo reemplazar sería, para que se mantenga como quiero el
        // gcd. Luego si realmente tengo que obtener un número más grande, sería
        // por cualquier múltilplo de gcd(B), y al ir reemplazando debería la multiplicación
        // terminar dando y si o si requeriría, o lo logaría con dichos múltiplos
        int haveCh = 0;
        forn (i,B.size()) {
            if (B[i] % dcm) {
                haveCh++;
                factPrim(dcm,F2);
            }
            else factPrim(B[i],F2);
        }

        // me fijaría si me passo, me quedo corto o igual en la factorización, y en base a eso
        // agregaría, quitaría de la respuesta, o la dejaría igual
        for (auto &i : F1) {
            if (!F2.count(i.fst))
        }
    }

};

int main() {
    FAST_IO;




    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
