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

const int MAXN = 1e5+2;

int rta[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    // voy a escalonar el array, tal que tenga la menor cantidad de escalones y n�meros por escal�n
    // para ello deben ser similares dichos n�meros, ya que cada valor representa LIS y LDS
    // eso ser�a entonces que me conviene en dividir en escalones tal que (cantidad por esccal�n)^2
    // se acerca lo m�s posible al n�mero. Entonces la cantidad menor de n� c/escal�n es sqrt(total)
    // luego el resto lo relleno con un �ltimo escal�n m�s chico

    int largoE = sqrt(N);

    int num = 1;
    forn (i,N) {
        int st = N-(largoE*(i+1));
        if (st < 0) st = 0;
        int v = 0;
        forsn (j,st,N) {if (num > N) break; rta[j] = num++; v++; if (v >= largoE) break;}
        if (num > N) break;
    }

    forn (i,N) cout << rta[i] << ' ';

    return 0;
}

/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!