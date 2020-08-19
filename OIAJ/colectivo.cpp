#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef vector<int> vi;

int binSrch(int n, vi s, int x) {
    int low = -1;
    int high = n;
    while (high-low>1) {
        int mid = (high+low) / 2;
        if (s[mid] < x) low = mid;
        else high = mid;
    }
    if (high >= n) return -1;
    return high;
}

char getAns(int &pos, int &v, int &F, vi &stop) {
    double ant,sig;
    int n2,n1,r;

    sig = binSrch(stop.size(),stop,pos);
    if (sig == -1) return 'O';
    if (sig - 1 < 0) return 'E';
    ant = stop[sig-1];
    sig = stop[sig];

    /// t = Δx/v (tPueblerino)
    /// x = v0*Δt (posColectivo en tPueblerino)
    /// parada - posColectivo = distParada
    /// distParada / freqColectivo = numColectivo (numColectivo que agarro según F, relativamente)
    /// ceil(numColectivo) (evita imprecisiones de división)

    /// ecuación combinada: (evita errores de redondeo al manejarse con ints:
    n1 = ceil(((sig - pos) / v * 60 - sig) / F);
    n2 = ceil(((pos - ant) / v * 60 - ant) / F);

    r = n1-n2; // diferencia hacia cada lado

    if (r == 0) return 'I';
    if (r > 0) return 'O';
    else return 'E';
    // tPueb = (abs(sig - pos) / v)
    // tCole  = ceil(tPueb/(sig/60))*F
}

string colectivo(vector<int> paradas, vector<int> pueblerinos, vector<int> velocidades, int F)
{
    string r;
    sort(paradas.begin(),paradas.end());
    forn (i,pueblerinos.size()) {
        r+=getAns(pueblerinos[i],velocidades[i],F,paradas);
    }
    return r;
}


#ifndef EVAL
    #include <iostream>

    int main()
    {
        freopen("colectivo1.in","r",stdin);

        int N,P,F;
        cin >> N >> P >> F;
        vector<int> paradas;
        paradas.reserve(N);
        for (int i=0;i<N;i++)
        {
            int x; cin >> x;
            paradas.push_back(x);
        }
        vector<int> pueblerinos, velocidades;
        pueblerinos.reserve(P);
        velocidades.reserve(P);
        for (int i=0;i<P;i++)
        {
            int ubicacion, velocidad;
            cin >> ubicacion >> velocidad;
            pueblerinos.push_back(ubicacion);
            velocidades.push_back(velocidad);
        }
        cout << colectivo(paradas, pueblerinos, velocidades, F) << endl;
        return 0;
    }
#endif
