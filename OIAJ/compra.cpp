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

const int MAXC = 1e5+2;
const int MAXP = 1e4+2;
const int INF = 2e9+2;

// ********** IMPORTANTE!!!!!!!!!!!!!!!! ************
// NO MODIFICAR DE NINGUNA MANERA ESTOS STRUCTS!!! **
struct PQ{ int precio, cantidad ; } ; // ************
struct FQ{ int fabricante, cantidad ; } ; // ********
// **************************************************
// **************************************************

ii minByCant[MAXC], minByPrice[MAXC];

int compra( int P, vector< PQ > fabricantes, vector< PQ > compradores, vector< FQ > &Fab, int & Comp ) {
    forn (i,fabricantes.size()) {
        if (fabricantes[i].precio < minByPrice[fabricantes[i].cantidad].fst or !minByPrice[fabricantes[i].cantidad].fst)
            minByPrice[fabricantes[i].cantidad] = {fabricantes[i].precio, i};

        int calc = fabricantes[i].precio*fabricantes[i].cantidad;
        if (calc > P) continue;
        if (calc < minByCant[fabricantes[i].cantidad].fst or !minByCant[fabricantes[i].cantidad].fst)
            minByCant[fabricantes[i].cantidad] = {calc, i};
    }
    ii miniP = {INF,-1};
    dforn (i,MAXC) { // guardo el precio mínimo si tengo una cantidad <= p
        if (minByCant[i].fst and minByCant[i].fst < miniP.fst)
            miniP = minByCant[i];
        minByCant[i] = miniP;
    }
    miniP = {INF,-1};
    forn (i,MAXC) { // guardo el precio mínimo si tengo una cantidad >= p
        if (minByPrice[i].fst and minByPrice[i].fst < miniP.fst)
            miniP = minByPrice[i];
        minByPrice[i] = miniP;
    }

    int win = -1, myF = -1, myCant;
    forn(i,compradores.size()) {
        int calc = compradores[i].cantidad*compradores[i].precio;
        if ((calc - minByCant[compradores[i].cantidad].fst) > win and
                minByCant[compradores[i].cantidad].fst != -1) {
            win = (calc - minByCant[compradores[i].cantidad].fst);
            myF = minByCant[compradores[i].cantidad].snd+1;
            myCant = fabricantes[myF-1].cantidad;
            Comp = i+1;
        }

        if (minByPrice[compradores[i].cantidad].snd == -1) continue;
        int calc2 = minByPrice[compradores[i].cantidad].fst*compradores[i].cantidad;
        if ((calc - calc2) > win and calc2 <= P) {
            win = (calc - calc2);
            myF = minByPrice[compradores[i].cantidad].snd+1;
            myCant = compradores[i].cantidad;
            Comp = i+1;
        }
    }

    if (win == -1) Comp = 0;
    else Fab.pb({myF,myCant});
    return win;
}

static const auto ______ = []() {
    FAST_IO; return 0;
}();
