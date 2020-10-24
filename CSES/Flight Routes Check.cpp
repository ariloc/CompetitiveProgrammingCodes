#include <bits/stdc++.h>

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

const int MAXN = 1e5;

void fastscan (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    if (c<'0'||c>'9') c=getchar_unlocked();
    for(; c>='0' && c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

vi G[MAXN];
bitset<MAXN> matched,comps,done;
int tin[MAXN], col[MAXN], actT = 1, prox_libre = 1;

vi pila;
int tarjan (int st) {
    tin[st] = actT++;
    pila.pb(st);

    int meT = actT-1;
    for(auto &i : G[st]) {
        if (!tin[i]) meT = min(meT,tarjan(i));
        if (!matched[i]) meT = min(meT,tin[i]);
    }

    if (meT >= tin[st]) while(not pila.empty()) {
        int e = pila.back(); pila.pop_back();
        col[e] = prox_libre; matched[e] = true;
        if (e == st) {prox_libre++; break;}
    }

    return meT;
}

bool canReach(int st, int nd) {
    done[st] = true;
    for(auto &i : G[st]) {
        if (i == nd) return true;
        if (!done[i]) if(canReach(i,nd)) return true;
    }
    return false;
}

int main() {
    int n,m; fastscan(n); fastscan(m);

    forn(i,m) {
        int u,v; fastscan(u); fastscan(v); u--; v--;
        G[u].pb(v);
    }

    forn(i,n) if(!tin[i]) tarjan(i);
    int cnt = 0; vi repres;
    forn(i,n) if (!comps[col[i]]) {cnt++; repres.pb(i); comps[col[i]] = true;}
    if (cnt == 1) printf("YES");
    else {
        // entre dos componentes distintas no se pueden llegar todos a todos, pero si uno al otro
        // checkeo entonces dicho caso, así hago swap si es necesario
        if(canReach(repres[0],repres[1])) swap(repres[0],repres[1]);
        printf("NO\n%d %d",repres[0]+1,repres[1]+1);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
