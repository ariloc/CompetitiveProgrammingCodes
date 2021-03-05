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

const int MAXN = 12;
const int X[] = {0,1,0,-1,0,0};
const int Y[] = {1,0,-1,0,0,0};
const int Z[] = {0,0,0,0,1,-1};

struct coord {
    int x,y,z;
};

char layers[MAXN][MAXN][MAXN];
bool done[MAXN][MAXN][MAXN];

int main() {
    FAST_IO;

    int k,n,m; cin >> k >> n >> m;
    forn(l,k) forn(i,n) forn(j,m) cin >> layers[l][i][j];
    ii st; cin >> st.fst >> st.snd; st.fst--, st.snd--;

    queue<coord> Q;
    Q.push({st.snd,st.fst,0}); done[0][st.fst][st.snd] = true;
    int cnt = 0;
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();
        cnt++;

        forn(o,6) {
            int tX = e.x+X[o], tY = e.y+Y[o], tZ = e.z+Z[o];
            if (tX < 0 || tY < 0 || tZ < 0 || tX >= m || tY >= n || tZ >= k) continue;
            if (done[tZ][tY][tX] || layers[tZ][tY][tX] == '#') continue;
            done[tZ][tY][tX] = true;
            Q.push({tX,tY,tZ});
        }
    }

    cout << cnt;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
