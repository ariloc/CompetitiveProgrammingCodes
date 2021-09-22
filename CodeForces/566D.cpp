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

const int INF = 1e9+2;
const int MAXN = 2e5+5;

struct DS { // Union-Find con Path-Compression, porque why not.
    int p[MAXN], r[MAXN];
    void init() {
        memset(p,-1,sizeof(p));
        memset(r,-1,sizeof(r));
    }
    int find(int &x) {return (p[x] == -1) ? x : (p[x] = find(p[x]));}
    bool sameTeam (int &a, int &b) {return (find(a) == find(b));}
    void join (int a, int b) {
        if (sameTeam(a,b)) return;
        int x = find(a);
        int y = find(b);
        if (r[x] > r[y]) p[y] = x;
        else {
            p[x] = y;
            if (r[x] == r[y]) r[y]++;
        }
    }
};

DS UF;
set<int> limits;

int main() {
    UF.init();

    int n,q; scanf("%d %d",&n,&q);
    forn (i,n) limits.insert(i+1);

    int typ,a,b;
    forn (i,q) {
        scanf("%d %d %d",&typ,&a,&b);
        if (typ == 1) {
            UF.join(a,b);
        }
        else if (typ == 2) {
            vi toDel; // eliminaré
            auto it = limits.lower_bound(a); // empiezo uniendo desde el primero heterogéneo
            while (it != limits.end() and *it < b) {toDel.pb(*it); UF.join(*it,(*it)+1); it++;} // así voy uniendo todo lo heterogéneo en el rango
            forn(o,toDel.size()) limits.erase(toDel[o]); // homogeneizo el rango, así está registrado para la prox. Lo hago tal [a;b) pues uno hacia adelante
        }
        else {
            if (UF.sameTeam(a,b)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!