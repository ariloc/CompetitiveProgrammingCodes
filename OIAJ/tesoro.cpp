#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 120;
const int INF = 1e7+2;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

vector<string> calabozo;
int D[MAXN][MAXN][MAXN];
pair<ii,int> P[MAXN][MAXN][MAXN];

struct nodo {
    int x,y,f; // coords + flechas restantes
    int d; // dist acumulada
};

bool valid (int &a, int &b) {
    if (a < 0 or b < 0) return false;
    if (a >= calabozo[0].size() or b >= calabozo.size()) return false;
    return true;
}

ii tesoro = {-1,-1}; // ubicación del tesoro
int distF = INF, cantFlechasF = -1;

void bfs(int stX, int stY, int &F) {
    queue<nodo> Q;
    Q.push({stX,stY,F,1});

    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.x != -1 and calabozo[e.y][e.x] == 'T') {
            tesoro = {e.x,e.y};
            if (e.d < distF) {
                distF = e.d;
                cantFlechasF = e.f;
            }
            continue;
        }

        forn (i,4) {
            int tendX = e.x+X[i], tendY = e.y+Y[i]; // recordar y primero, luego x
            if (!valid(tendX,tendY)) continue;
            int flechasAct = (calabozo[tendY][tendX] == 'W' ? e.f-1 : e.f);
            if (D[tendX][tendY][flechasAct]) continue;
            if (calabozo[tendY][tendX] == 'P') continue;
            if (calabozo[tendY][tendX] == 'W' and !e.f) continue;

            D[tendX][tendY][flechasAct] = e.d+1;
            P[tendX][tendY][flechasAct] = {{e.x,e.y},e.f};

            Q.push({tendX,tendY,flechasAct,D[tendX][tendY][flechasAct]});
        }
    }
}

int main() {
    freopen("tesoro.in","r",stdin);
    freopen("tesoro.out","w",stdout);

    int y,x,F;
    scanf("%d %d %d",&y,&x,&F);

    forn (i,y) {
        char s[x+1];
        scanf("%s",s);
        calabozo.push_back(s);
    }

    P[0][0][F] = {{-1,0},F};
    bfs(-1,0,F);
    if (tesoro.fst == -1) {printf("imposible"); return 0;}

    printf("%d\n",distF-1);
    vector<ii> r;
    r.reserve(distF+2);
    for (pair<ii,int> i = {tesoro,cantFlechasF}; i.fst != make_pair(-1,0); i = P[i.fst.fst][i.fst.snd][i.snd])
        r.push_back({i.fst.fst,i.fst.snd});
    dforn(i,r.size()) printf("(%d,%d)\n",r[i].snd,r[i].fst);

    return 0;
}
