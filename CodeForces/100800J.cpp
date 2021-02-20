#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 65;
const int MAXP = 205;
const int TOPP = 50000;
const int X[] = {0,1,0,-1,0};
const int Y[] = {1,0,-1,0,0};

char mat[MAXN][MAXN];
bool sent[MAXP],prohib[MAXN][MAXN],auxP[MAXN][MAXN],arrive[MAXN][MAXN][2];
int idx[MAXP]; // L,R,U,D
vector<ii> paths[MAXP];

int main() {
    int r,c; scanf("%d %d ",&r,&c);
    ii st,nd; scanf("(%d %d) (%d %d)",&st.fst,&st.snd,&nd.fst,&nd.snd);
    st.fst--, st.snd--, nd.fst--, nd.snd--;
    forn(i,r) scanf("%s",mat[i]);
    int p; scanf("%d",&p);
    forn(i,p) {
        int x; scanf("%d",&x);
        forn(j,x) {
            int auxr,auxc; scanf(" (%d %d)",&auxr,&auxc), auxr--, auxc--; // row, col
            paths[i].pb({auxr,auxc});
        }
    }

    int rta = -1; arrive[st.fst][st.snd][0] = 1;
    forn(k,TOPP) { // máx turnos
        forn(i,r) forn(j,c) prohib[i][j] = arrive[i][j][1^(k&1)] = auxP[i][j] = 0; // reset

        forn(l,p) { // por los patrulleros
            ii aP = paths[l][idx[l]]; // r,c
            if (paths[l].size() > 1) {
                int sInd = (sent[l] ? -1 : 1);
                if (idx[l]+sInd < 0 || idx[l]+sInd >= (int)paths[l].size()) // invierto si me voy out of bounds
                    sent[l] ^= 1, sInd *= -1;
                idx[l] += sInd; // para la próxima
            }

            auxP[aP.fst][aP.snd] = 1;
        }

        // dp prohib
        bool stat = 0;
        forn(i,r) {
            stat = 0; forn(j,c) stat |= auxP[i][j], stat &= (mat[i][j] == '.'), prohib[i][j] |= stat;
            stat = 0; dforn(j,c) stat |= auxP[i][j], stat &= (mat[i][j] == '.'), prohib[i][j] |= stat;
        }
        forn(j,c) {
            stat = 0; forn(i,r) stat |= auxP[i][j], stat &= (mat[i][j] == '.'), prohib[i][j] |= stat;
            stat = 0; dforn(i,r) stat |= auxP[i][j], stat &= (mat[i][j] == '.'), prohib[i][j] |= stat;
        }

        forn(i,r) forn(j,c) {
            if (i == nd.fst && j == nd.snd && arrive[i][j][k&1]) rta = k;
            if (prohib[i][j] || !arrive[i][j][k&1]) continue;
            forn(o,5) {
                int tY = i+Y[o], tX = j+X[o];
                if (tY < 0 || tX < 0 || tY >= r || tX >= c) continue;
                if (mat[tY][tX] == '#') continue;
                arrive[tY][tX][1^(k&1)] = true;
            }
        }

        if (rta != -1) break;
    }

    if (rta == -1) printf("IMPOSSIBLE");
    else printf("%d",rta);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
