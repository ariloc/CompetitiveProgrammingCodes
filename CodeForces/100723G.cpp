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

const int MAXN = 505;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

int mat[MAXN][MAXN],done[MAXN][MAXN],h,w,d;
pair<int,ii> pts[MAXN*MAXN];

bool bfs (ii st) {
    int myH = mat[st.fst][st.snd];
    if (done[st.fst][st.snd] != -1) {
        if (done[st.fst][st.snd] == myH) return true; // si es de mi misma altura, no pasa nada, porque no es más alto
        return false; // de lo contrario chau
    }

    queue<ii> Q;
    Q.push(st); done[st.fst][st.snd] = myH;

    int maxF = myH;
    vector<ii> marked;
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        forn(k,4) {
            int tY = e.fst+Y[k], tX = e.snd + X[k];
            if (tY < 0 || tX < 0 || tY >= h || tX >= w) continue;
            if (done[tY][tX] != -1) {maxF = max(done[tY][tX],maxF); continue;} // si con el margen para los de misma menos vale, entonces más aún para mí, más bajo
            if (mat[tY][tX] <= myH-d) continue; // marco todos los > myH-d, que sería el rango de llegar bien "desde mi misma altura"
            done[tY][tX] = myH; marked.pb({tY,tX});
            Q.push({tY,tX});
        }
    }

    // marcaré del más grande que haya tocado, y si no, será de mi altura
    for (auto &i : marked) done[i.fst][i.snd] = maxF;
    if (maxF > myH) return false;

    return true;
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        scanf("%d %d %d",&h,&w,&d);
        forn(i,h) forn(j,w) scanf("%d",&mat[i][j]);

        forn(i,h) forn(j,w) done[i][j] = -1; // reset

        forn(i,h) forn(j,w) pts[i*w+j] = {mat[i][j],{i,j}};
        sort(pts,pts+h*w,greater<pair<int,ii>>());

        int rta = 0;
        forn(i,h*w) rta += bfs(pts[i].snd);

        printf("%d\n",rta);
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
