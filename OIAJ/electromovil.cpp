#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i<int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i<int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

vi respuesta;

vector<int> electromovil(int E, vector<int> ubicacion, vector<int> autonomia)
{
    int last = ubicacion[0] + autonomia[0];
    ii best = {-1,-1}; // ganancia de distancia || posición en vector
    forsn (i,1,E) {
        if (ubicacion[i] <= last) {
            int autonomiaNeta = ubicacion[i] + autonomia[i];

            if (i == E-1) {
                respuesta.push_back(ubicacion[i]);
                return respuesta;
            }

            if (best.fst == -1 or autonomiaNeta > best.fst) {
                best.fst = autonomiaNeta;
                best.snd = i;
            }
        }
        else {
            if (best.fst == -1) {
                vi vacio;
                return vacio;
            }
            last = ubicacion[best.snd] + autonomia[best.snd];
            respuesta.push_back(ubicacion[best.snd]);
            best.fst = -1;
            best.snd = -1;
            i--;
        }
    }
}
