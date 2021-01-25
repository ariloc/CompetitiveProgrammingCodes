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

int main() {
    FAST_IO;

    ll n;
    while (cin >> n) {
        if (n == -1) break;
        n++;
        ll s = 0, OG = n;

        ll exp = 1, prvExp = -1;
        bool flip = false;
        while (n) {
            while (exp*5 <= n) exp *= 5;

            if (prvExp != -1) {
                ll aux = exp;
                while (aux < prvExp) {
                    aux *= 5;
                    if (aux < prvExp && (((OG-n)/aux)&1)) flip = !flip;
                }
            }

            ll orgExp = exp; prvExp = exp;

            //cerr << exp << ' ' << n << ' ' << (OG-n)%exp << endl;

            if (exp == 1) {
                if (!flip) s += n;
                break;
            }


            //bool didSwap = false;
            ll one = n/(exp*2), zero = ((n/exp)+1)/2, zeroM = 0, oneM = 0;
            //bool prvSwap = false;
            if ((((OG-n)/exp)&1)) swap(one,zero);
            if (flip) swap(one,zeroM), swap(zero,oneM);
            //cerr << n << ' ' << exp << ' ' << one << ' ' << zero << ' ' << oneM << ' ' << zeroM << ' ' << flip << endl;

            while (exp > 5) {
                ll auxO = 0, auxZ = 0, auxOM = 0, auxZM = 0;
                //cerr << one << ' ' << zero << endl;
                auxZM = one*3 + oneM*2;
                auxOM = one*2 + oneM*3;
                auxO = zero*2 + zeroM*3;
                auxZ = zero*3 + zeroM*2;
                one = auxO, zero = auxZ, zeroM = auxZM, oneM = auxOM;
                exp /= 5;
            }

            s += zero*exp+zeroM*exp;
            //cerr << s << endl;
            //cerr << zero*exp+zeroM*exp << endl;
            if ((((OG-(n%orgExp))/orgExp))&1) flip = !flip;
            //cerr << flip << "!!!" << endl;
            n %= orgExp, exp = 1;
        }


        cout << s << '\n';

        //cout << s+1 << endl;
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
