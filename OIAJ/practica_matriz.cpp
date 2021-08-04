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

const int INF = 11;

struct Resultado
{
    long long suma, producto, maximo, minimo;
};

ll s = 0,p = 1,maxi = -1,mini = INF;

void procesaMatriz(vector<vector<int> > matriz, vector<long long> &resultadoEnArreglo, Resultado &resultadoEnRegistro)
{
    forn (i,matriz.size())
        forn (j,matriz[i].size()) {
            int act = matriz[i][j];
            s+=act;
            p*=act;
            if (act > maxi) maxi = act;
            if (act < mini) mini = act;
        }

    resultadoEnArreglo.push_back(s);
    resultadoEnArreglo.push_back(p);
    resultadoEnArreglo.push_back(maxi);
    resultadoEnArreglo.push_back(mini);

    resultadoEnRegistro = {s,p,maxi,mini};
}