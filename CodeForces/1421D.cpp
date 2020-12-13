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

ll comb[2][2];
ll x[2],y[2];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        ll xf,yf; cin >> xf >> yf; swap(xf,yf);
        ll c1,c2,c3,c4,c5,c6; cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

        // me guardo el mejor movimiento para cada propósito
        x[1] = min(c2,c1+c3); // x positivo
        x[0] = min(c5,c4+c6); // x negativo
        y[1] = min(c6,c1+c5);
        y[0] = min(c3,c4+c2);
        comb[1][1] = min(x[1]+y[1],c1);
        comb[1][0] = min(x[1]+y[0],c2+c3);
        comb[0][0] = min(x[0]+y[0],c4);
        comb[0][1] = min(x[0]+y[1],c5+c6);

        cout << min(abs(xf)*x[xf > 0]+abs(yf)*y[yf > 0],
                    min(abs(xf),abs(yf))*comb[xf > 0][yf > 0] +
                        (max(abs(xf),abs(yf))-min(abs(xf),abs(yf))) *
                        (abs(xf) > abs(yf) ? x[xf > 0] : y[yf > 0])) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
