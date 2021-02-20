#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 1e8+5;
const int MAXQ = 1e5+5;
const int INF = 2e9;
const ll INFL = 9e18;

vi ratios,stairs,elev;

void proc (ll &rta, int x1, int x2, int y1, int y2, int den, vi::iterator &it, vi &vec) {
    if (it != vec.begin()) {
        int aux = (*(prev(it)));
        rta = min(rta,(ll)abs(x1-aux)+abs(aux-x2)+(abs(y1-y2)+den-1)/den);
    }
    if (it != vec.end()) {
        int aux = (*it);
        rta = min(rta,(ll)abs(x1-aux)+abs(aux-x2)+(abs(y1-y2)+den-1)/den);
    }
}

int main() {
    FAST_IO;

    int n,m,cl,ce,v; cin >> n >> m >> cl >> ce >> v;

    forn(i,cl) {
        int x; cin >> x;
        stairs.pb(x);
    }
    forn(i,ce) {
        int x; cin >> x;
        elev.pb(x);
    }

    int q; cin >> q;
    forn(i,q) {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        swap(x1,y1), swap(x2,y2); // así los x es en horizontal, y en vertical

        auto elev_l = lower_bound(all(elev),min(x1,x2)); // primer elevador a la izq
        auto elev_r = upper_bound(all(elev),max(x1,x2)); // primer elevador a la der
        auto stairs_l = lower_bound(all(stairs),min(x1,x2)); // primera escalera a la izq
        auto stairs_r = upper_bound(all(stairs),max(x1,x2)); // primera escalera a la der

        ll rta = INFL;
        proc(rta,x1,x2,y1,y2,v,elev_l,elev);
        proc(rta,x1,x2,y1,y2,v,elev_r,elev);
        proc(rta,x1,x2,y1,y2,1,stairs_l,stairs);
        proc(rta,x1,x2,y1,y2,1,stairs_r,stairs);
        if (y1 == y2) rta = min(rta,(ll)abs(x1-x2)); // YEAH, DON'T FORGET WHEN YOU DON'T HAVE TO USE ELEVATORS, AND THERE'S NO ONE NEAR SO THE CONDITION GOES FALSE AND FAILS proc()

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
