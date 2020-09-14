
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

struct segm {
    int x,ly,ry;

    bool operator< (const segm &o) const{
        if (o.x == x) return ry < o.ry;
        return x < o.x;
    }
};

const int MAXD = 1e6;
const int INF = 1e9+5;
const int MAXDD = MAXD+5;
const int MAXN = 3e5+5;

segm lines[MAXN];
int FT[MAXDD];
int ind = 0;

void setFT (int p, int v) {
    for (int i = p; i < MAXDD; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    // divido por aquellos segmentos que cortan lado a lado
    // luego las intersecciones de segmentos al venir desde los bordes, también indican además nuevos limites -> nuevas áreas
    ll cnt = 1;
    forn(i,n) {
        int y,lx,rx; cin >> y >> lx >> rx;
        if (lx == 0 and rx == MAXD) cnt++;
        lines[ind++] = {lx+2,y+2,-INF}; // agregar primero
        lines[ind++] = {rx+2,y+2,INF}; // sacar último
    }

    forn(i,m) {
        int x,ly,ry; cin >> x >> ly >> ry;
        if (ly == 0 and ry == MAXD) cnt++;
        lines[ind++] = {x+2,ly+2,ry+2};
    }

    sort(lines,lines+ind);

    forn(i,ind) {
        if (abs(lines[i].ry) == INF) {
            if (lines[i].ry < 0) setFT(lines[i].ly,1);
            else setFT(lines[i].ly,-1);
        }
        else cnt += getFT(lines[i].ry)-getFT(lines[i].ly-1);
    }

    cout << cnt;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
