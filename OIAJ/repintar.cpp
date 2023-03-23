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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 2005;
const int MAXR = 52;
const int INF = 2e9;
const int X[] = {1,0,-1,0};
const int Y[] = {0,1,0,-1};

struct state {
    state(){}
    state(ll a, int b) : mk(a), col(b) {}

    ll mk;
    int col;
};

char mat[MAXN][MAXN];
bool done[MAXN][MAXN], ady[MAXR][MAXR];
int col[MAXN][MAXN];
int colNode[MAXN];
vi G[MAXR];
int n, regions = 0;
map<ll, int> costs;
map<ll, state> S;

void dfs (int y, int x) {
    done[y][x] = true;
    col[y][x] = regions;
    forn(k,4) {
        int tX = x + X[k], tY = y + Y[k];
        if (tX < 0 || tY < 0 || tX >= n || tY >= n) continue;
        if (done[tY][tX]) continue;
        if (mat[tY][tX] != mat[y][x]) continue;
        dfs(tY,tX);
    }
}

int getId (char c) {
    if (c == 'R') return 0;
    if (c == 'A') return 1;
    return 2;
}

int solve (ll mk, int colact) {
    if (mk == (1LL<<regions)-1) return 0;
    
    auto it = costs.find(mk);
    map<ll,state>::iterator it2;

    if (it != costs.end())
        return (*it).snd;

    it = costs.insert({mk, INF}).fst;
    it2 = S.insert({mk, state(-1, -1)}).fst;

    pair<ll,int> tg[3] = {{0,0}, {0,1}, {0,2}};
    forn(i,regions) if (mk&(1LL<<i))
        for (auto &j : G[i]) {
            tg[colNode[j]].fst |= (1LL<<j);
        }

    forn(k,3) {
        if (colact == k) continue;
        state nxt = state(mk | tg[k].fst, k);
        if (nxt.mk == mk) continue;

        int cost = solve(nxt.mk, nxt.col) + 1;
        if (cost < (*it).snd) {
            (*it).snd = cost;
            (*it2).snd = nxt;
        }
    }

    return (*it).snd;
}

int main() {
    freopen("repintar.in","r",stdin);
    freopen("repintar.out","w",stdout);

    scanf("%d",&n);
    forn(i,n) scanf("%s", mat[i]);

    forn(i,n) forn(j,n) if (!done[i][j]) {
        dfs(i,j);
        colNode[regions] = getId(mat[i][j]);
        regions++;
    }

    forn(i,n) forn(j,n) forn(k,4) {
        int tX = j + X[k], tY = i + Y[k];
        if (tX < 0 || tY < 0 || tX >= n || tY >= n) continue;
        if (mat[i][j] != mat[tY][tX]) {
            int a = col[i][j], b = col[tY][tX];
            ady[a][b] = ady[b][a] = true;
        }
    }

    forn(i,regions) forn(j,regions) if (ady[i][j]) G[i].pb(j);

    printf("%d\n", solve(1,colNode[0]));
    state init = S[1];
    while (init.mk > 0) {
        printf("%c",init.col == 0 ? 'R' : init.col == 1 ? 'A' : 'V');
        init = S[init.mk];
    }
    
    return 0;
}


