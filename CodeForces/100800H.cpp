#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
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
#define PI acos(-1)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;
const ld EPS = 1e-6;
const ld INF = 1e9+5;

struct pt {
    ld x,y;

    pt (){};
    pt(ld xx, ld yy) : x(xx), y(yy) {};

    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    ld ang() {return atan(y/x);}

    bool operator< (const pt &o) const {
        if (x == o.x) return y < o.y;
        return x < o.x;
    }
};

pt ptos[MAXN];
pair<ld,ld> edif[MAXN];
ii edifPtos[MAXN]; // indice del que me tapó
int pMaxL[MAXN], pMaxR[MAXN];
bitset<MAXN> passL,passR;
ld rta[MAXN];

int main() {
    FAST_IO;

    forn(i,MAXN) edifPtos[i] = {-1,-1};

    int n; cin >> n;
    ptos[0] = {0,INF}, ptos[n+1] = {INF,INF};
    forn(i,n) cin >> ptos[i+1].x >> ptos[i+1].y;

    // primero mayor (o igual) a ambos lados
    dforsn(i,1,n+1) {int j; for (j = i+1; ptos[j].y < ptos[i].y; j = pMaxR[j]); pMaxR[i] = j;}
    forsn(i,1,n+1) {int j; for(j = i-1; ptos[j].y < ptos[i].y; j = pMaxL[j]); pMaxL[i] = j;}

    // iremos desde los más altos a los de menos
    priority_queue<ii> tall;

    forn(i,n) { // init
        edif[i+1] = {0,PI};
        tall.push({ptos[i+1].y,i+1});
    }

    passL[0] = passL[n+1] = passR[0] = passR[n+1] = 1; // marco bordes
    while (!tall.empty()) {
        auto e = tall.top(); tall.pop();
        pt meAct = ptos[e.snd];
        //if (e.snd == 8) cerr << "LOLLL" << ' ' << passR[e.snd-1] << ' ' << ptos[e.snd-1].y << ' ' << me.y << ' ' << edifPtos[e.snd].fst << endl;

        pt me = meAct; int ind = e.snd;
        for (int i = ind-1; !passL[i] && ptos[i].y <= me.y; i = pMaxL[i]) {
            passL[i] = true;
            pt vec = ptos[i]-me;
            int parent = ind;
            ld ang = PI-max((ld)0,vec.ang());
            while (edifPtos[parent].snd != -1) {
                ld calc = PI-max((ld)0,(ptos[i]-ptos[edifPtos[parent].snd]).ang());
                if (calc < ang) ang = calc, parent = edifPtos[parent].snd;
                else break;
            }
            me = ptos[parent], ind = parent;
            edif[i].snd = ang;
            edifPtos[i].snd = parent;
        }

        me = meAct, ind = e.snd;
        for (int i = ind+1; !passR[i] && ptos[i].y <= me.y; i = pMaxR[i]) {
                //if (e.snd == 8) cerr << i << " !!!" << endl;
            passR[i] = true;
            pt vec = ptos[i]-me;
            int parent = ind;
            ld ang = -min((ld)0,vec.ang());
            while (edifPtos[parent].fst != -1) {
                ld calc = -min((ld)0,(ptos[i]-ptos[edifPtos[parent].fst]).ang());
                //if (e.snd == 8) cerr << "OKKA" << ' ' << calc << ' ' << ang << ' ' << endl;
                if (calc > ang) ang = calc, parent = edifPtos[parent].fst;
                else break;
            }
            me = ptos[parent], ind = parent;
            edif[i].fst = ang;
            edifPtos[i].fst = parent;
        }
    }

    forsn(i,1,n+1) {
        //cerr << edif[i].fst << ' ' << edif[i].snd << ' ' << edifPtos[i].fst << ' ' << edifPtos[i].snd << endl;
        cout << fixed << setprecision(10) << ((edif[i].snd-edif[i].fst)/PI)*12 << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
