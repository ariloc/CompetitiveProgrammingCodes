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

const int MAXN = 2100;
const int MAXA = 26;

int rta[MAXN][MAXN];
char id[MAXN*MAXN];
vector<ii> posics[MAXN*MAXN];
bool posib[MAXA];

const int Y[] = {0,1,0,1};
const int X[] = {0,0,1,1};
const int dX[] = {0,1,0,-1};
const int dY[] = {1,0,-1,0};
int prox_libre = 2;
bool solve (int y, int x, int N) {
    if (N <= 1) return (rta[y][x] > 0);

    int n = (N >> 1);

    bool q[] = {0,0,0,0};
    bool inside = false;
    forn(k,4) 
        if ((q[k] = solve(y + Y[k]*n, x + X[k]*n, n))) inside = true;

    if (inside) {
        forn(k,4) if (!q[k])
            rta[y+n-1+Y[k]][x+n-1+X[k]] = prox_libre, posics[prox_libre].pb({y+n-1+Y[k],x+n-1+X[k]});
        prox_libre++;

        forn(k,4) if (!q[k]) solve(y + Y[k]*n, x + X[k]*n, n);
        return true;
    }

    return false;
}

vector<ii> neighbors (int y, int x) {
    vector<ii> ret;
    forn(k,4) {
        int tY = y + dY[k], tX = x + dX[k];
        if (tY < 0 || tX < 0 || tY >= MAXN || tX >= MAXN) continue;
        ret.pb({tY,tX});
    }
    return ret;
}

int main() {
    int n,r,c; scanf("%d %d %d",&n,&r,&c);
    if (n == 1) return printf("."), 0;

    rta[r-1][c-1] = 1;

    solve(0,0,n);

    forn(i,MAXN*MAXN) if (!posics[i].empty()) {
        forn(j,MAXA) posib[j] = 1;
        for (auto &j : posics[i]) {
            auto aux = neighbors(j.fst, j.snd);
            for (auto &k : aux)
                if (id[rta[k.fst][k.snd]] && rta[k.fst][k.snd] != rta[j.fst][j.snd])
                    posib[id[rta[k.fst][k.snd]] - 'A'] = 0;
        }
        auto pto = posics[i][0];
        forn(j,MAXA) if (posib[j]) {id[rta[pto.fst][pto.snd]] = j + 'A'; break;}
    }

    forn(i,n) forn(j,n) {
        if (rta[i][j] >= 2) printf("%c",id[rta[i][j]]);
        else printf(".");
        if (j == n-1) puts("");
    }

    return 0;
}