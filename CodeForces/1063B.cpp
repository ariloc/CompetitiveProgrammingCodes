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

const int MAXN = 2005;
const int X[] = {0,0,1,-1}; // U,D,R,L
const int Y[] = {1,-1,0,0};

char lab[MAXN][MAXN];
bool done[MAXN][MAXN];

struct nodoBFS {
    ii v; int maxL, maxR;
};

int main() {
    int n,m; scanf("%d %d",&n,&m);
    ii st; scanf("%d %d",&st.fst,&st.snd); st.fst--, st.snd--;
    int maxL, maxR; scanf("%d %d",&maxL,&maxR);
    forn(i,n) scanf("%s",lab[i]);

    vector<nodoBFS> Q[2]; Q[0].pb({st,maxL,maxR}); done[st.fst][st.snd] = true;
    bool act = 0;
    // esto debería funcionar porque siempre quiero llegar con la mínima cantidad de pasos
    // como los de misma coordenada están limitados, no puedo llegar a un destino gastando más de uno
    // que del otro y al revés, siempre es igual o mayor la cant total.
    while (!Q[0].empty() || !Q[1].empty()) {
        while (!Q[act].empty()) {
            auto e = Q[act].back(); Q[act].pop_back();

            forn(k,4) {
                int tY = e.v.fst+Y[k], tX = e.v.snd+X[k];
                if (tY < 0 || tX < 0 || tY >= n || tX >= m) continue;
                if (done[tY][tX] || lab[tY][tX] == '*') continue;
                if ((k == 2 && e.maxR <= 0) || (k == 3 && e.maxL <= 0)) continue;

                done[tY][tX] = true;
                if (k > 1) Q[1^act].pb({{tY,tX},e.maxL-(k==3),e.maxR-(k==2)});
                else Q[act].pb({{tY,tX},e.maxL,e.maxR});
            }
        }
        act ^= 1;
    }

    int cnt = 0;
    forn(i,n) forn(j,m) if (done[i][j]) cnt++;
    printf("%d",cnt);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
