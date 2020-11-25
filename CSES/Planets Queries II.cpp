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

const int MAXN = 2e5+2;

void fastscan(int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    if(c<'0'||c>'9') c=getchar_unlocked();
    for(; c>='0'&&c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

vi GB[MAXN];
vector<ii> queries[MAXN];
bitset<MAXN> passed,done;
int tin[MAXN], tin_dfs[MAXN], G[MAXN], rta[MAXN], cycleSz[MAXN], t = 1, cycles = 0;
ii cycleLoc[MAXN]; // ubic en ciclos si están en uno

vi path;
void findCycle(int st) {
    tin[st] = t++;
    path.pb(st);

    int i = G[st];
    if (!tin[i]) findCycle(i);
    else if (!passed[i]) {
        vi tmp;
        while (!path.empty()) {
            auto e = path.back(); path.pop_back();
            tmp.pb(e); if (e == i) break;
        }
        cycleSz[cycles++] = tmp.size(); // registro tamaño
        int ind = 0;
        dforn(j,tmp.size())
            cycleLoc[tmp[j]] = {cycles-1,ind++};
    }

    if (!path.empty() && path.back() == st) path.pop_back(); // finish emptying
    passed[st] = true;
}

void dfs(int st) {
    tin_dfs[st] = t++;
    path.pb(st);

    for (auto &i : queries[st]) {
        if (!tin_dfs[i.fst]) rta[i.snd] = -1; // no pongo continue porque igual se puede dar la siguiento condición
        if (cycleLoc[i.fst].fst == cycleLoc[path[0]].fst) { // si está en ciclo mismo que el del cual salgo
            int cycleSzTmp = cycleSz[cycleLoc[i.fst].fst];
            rta[i.snd] = ((cycleLoc[i.fst].snd-cycleLoc[path[0]].snd+cycleSzTmp)%cycleSzTmp) + (tin_dfs[st]-tin_dfs[path[0]]);
        }
        else if (!done[i.fst] && tin_dfs[i.fst]) // si pasé y no marqué, y no está en ciclo, entonces está abajo
            rta[i.snd] =  (tin_dfs[st]-tin_dfs[i.fst]);
    }

    for (auto &i : GB[st])
        if (!tin_dfs[i] && cycleLoc[i].fst == -1) dfs(i); // no veré atrás en el ciclo

    path.pop_back(); // emptying
    done[st] = true; t--;
}

int main() {
    forn(i,MAXN) {cycleLoc[i] = {-1,-1}; rta[i] = -1;} // reset
    int n,q; fastscan(n); fastscan(q);

    forn(i,n) {
        int x; fastscan(x); x--;
        G[i] = x; // teleporter
        GB[x].pb(i); // "fake" back edges
    }

    forn(i,q) {
        int a,b; fastscan(a); fastscan(b); a--; b--;
        queries[a].pb({b,i}); // con id para orden
    }

    // finding cycles
    forn(i,n) if (!passed[i]) findCycle(i); t = 1;
    forn(i,n) if (!done[i] && cycleLoc[i].fst != -1) dfs(i);

    forn(i,q) printf("%d\n",rta[i]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
