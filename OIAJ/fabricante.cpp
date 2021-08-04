#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int fabricante( int P, int precioVenta, int cantidadVenta, vector< int > precioCompra, vector< int > cantidadCompra, int & fabricante )
{
    int gotC = precioVenta*cantidadVenta;
    int bestG = -1, chosen;
    forn (i,precioCompra.size()) {
        if (cantidadVenta <= cantidadCompra[i]) {
            int calc1 = cantidadCompra[i]*precioCompra[i];
            if (calc1 > P) continue;
            int calc = gotC-calc1;
            if (calc > bestG and calc1 <= gotC)
                {bestG = calc; chosen = i+1;}
        }
        else {
            int calc1 = precioCompra[i]*cantidadVenta;
            if (calc1 > P) continue;
            int calc = gotC-calc1;
            if (calc > bestG and calc1 <= gotC)
                {bestG = calc; chosen = i+1;}
        }
    }
    fabricante = (bestG < 0 ? 0 : chosen);
    return (bestG < 0 ? -1 : bestG);
}