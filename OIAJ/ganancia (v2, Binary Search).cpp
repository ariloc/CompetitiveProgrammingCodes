#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

// *********** IMPORTANTE!!!!!! ********************
// NO MODIFICAR DE NINGUNA MANERA ESTE STRUCT!!!!!**
struct PQ{ int precio, cantidad; } ; //  ***********
// *************************************************
// *************************************************

int const MAXN = 1e5+5;
int const INF = 2e9+200;

struct myfab {
    int p,c,id;

    bool operator< (const myfab &o) const {
        return c < o.c;
    }
};

ii minprecio[MAXN], minprod[MAXN];

int ganancia( int P, vector< PQ > fabricantes, vector< PQ > compradores, int & Fab, int & Comp ) {
    Fab = 0;
    Comp = 0;

    vector<myfab> fab;
    forn(i,sz(fabricantes)) fab.pb({fabricantes[i].precio,fabricantes[i].cantidad,i+1});
    sort(all(fab));

    forn(i,MAXN) minprecio[i] = minprod[i] = {INF,-1};

    int n = sz(fab);
    dforn(i,n) minprod[i+1] = min(minprod[i+2], {fab[i].p * fab[i].c, i});
    forn(i,n) minprecio[i+1] = min(minprecio[i], {fab[i].p, i});

    int m = sz(compradores);
    int maxi = -1;
    forn(i,m) {
        int earn = compradores[i].precio * compradores[i].cantidad;
        int ind = lower_bound(all(fab),(myfab){-INF,compradores[i].cantidad})-fab.begin()+1;
        if (minprod[ind].fst <= P && minprod[ind].snd != -1 && earn - minprod[ind].fst > maxi)
            maxi = earn - minprod[ind].fst, Fab = fab[minprod[ind].snd].id, Comp = i+1;

        --ind;
        int buy = minprecio[ind].fst * compradores[i].cantidad;
        if (buy <= P && minprecio[ind].snd != -1 && earn - buy > maxi)
            maxi = earn - buy, Fab = fab[minprecio[ind].snd].id, Comp = i+1;
    }

    return maxi;
}

static const auto ______ = []() {
    FAST_IO; return 0;
}();

