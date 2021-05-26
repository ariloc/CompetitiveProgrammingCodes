#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 2e5+5;

struct edges {
    int v; ll w;

    bool operator< (const edges &o) const {
        return w > o.w; // al revés
    }
};

struct DS {
    vi p,r;
    vector<vi> pacientes;
    vector<vi> camas;

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        forn(i,N) p[i] = i;

        pacientes.assign(N,{});
        camas.assign(N,{});
    }

    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}

    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);

        // MERGE
        p[x] = y;
        while (!pacientes[x].empty())
            pacientes[y].pb(pacientes[x].back()), pacientes[x].pop_back();
        while (!camas[x].empty())
            camas[y].pb(camas[x].back()), camas[x].pop_back();

        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

vector<edges> G[MAXN];
int deg[MAXN];
bitset<MAXN> done;
DS UF;

void asignar(int puebloPaciente, int puebloCama);

long long camas(vector<int> &p, vector<int> &c, vector<int> &a, vector<int> &b, vector<int> &l) {
    int n = p.size();

    forn(i,n) {
        int cnt = min(p[i],c[i]);
        c[i] -= cnt, p[i] -= cnt;
        while (cnt--) asignar(i+1,i+1);
    }

    forn(i,n-1) { // n-1 aristas
        deg[a[i]-1]++, deg[b[i]-1]++;
        G[a[i]-1].pb({b[i]-1,l[i]});
        G[b[i]-1].pb({a[i]-1,l[i]});
    }

    UF.init(n+5);

    forn(i,n) {
        while (p[i]--) UF.pacientes[i].pb(i);
        while (c[i]--) UF.camas[i].pb(i);
    }

    queue<edges> Q;
    forn (i,n) if (deg[i] == 1) Q.push({i,0LL});

    ll cost = 0;
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (done[e.v]) continue;

        deg[e.v] = 0, done[e.v] = true;

        int ccmp = UF.find(e.v);

        while (!UF.camas[ccmp].empty() && !UF.pacientes[ccmp].empty()) {
            asignar(UF.pacientes[ccmp].back()+1,UF.camas[ccmp].back()+1);
            UF.camas[ccmp].pop_back(), UF.pacientes[ccmp].pop_back();
        }

        ll sobra = (UF.pacientes[ccmp].size()+UF.camas[ccmp].size());
        for (auto &i : G[e.v]) {
            if ((--deg[i.v]) == 1)
                if (!done[i.v]) Q.push({i.v,e.w+i.w});

            //cerr << i.w << ' ' << sobra << ' ' << e.v << ' ' << i.v << " !!!" << endl;

            if (!done[i.v]) {
                cost += i.w * sobra; // cobro cada vez que paso
                UF.join(e.v,i.v);
            }
        }
    }

    return cost;
}

// Rompamos el árbol desde las hojas. Si me sobran camas, de una forma u otra tendrán que llegar
    // Y si hay pacientes, les tendrán que llegar camas.
    // La pregunta es, ¿me afectan los pesos de los caminos?
    // Si es el óptimo, entonces estoy bien. Pero si había uno más cercano que era mejor, tenemos que pensar
    // que si teníamos camas de antes pesadas que no usamos, entonces van a seguir acumulando a peor
    // entonces sea como sea está definido el proceso.
    // Lo que si puedo cambiar, es que debería al sacar un nodo y asignar para sus hojas, hacerlo de la forma más
    // óptima posible. Entonces se reduce a hacer un matching entre ambos conjuntos 

    // Puedo usar Union-Find para ir uniendo los conjuntos, y recorro desde las hojas a los padres
    // Entonces cuando saco un nodo, siempre saco los mayores, porque esos mi irían sumando más cantidad todavía
    // y no quiero que pase eso. El DSU me permite hacer en log las uniones de los conjuntos.
    // Me mantengo los ids de pueblos, que de hecho puedo hacer uno por persona porque <= 3e5
    // Además tengo que debo usar sets, para saber rápidamente para cada uno, el más lejos....
    // Peeero no hace falta. Porque sea como sea, todos los que tengo suman lo mismo, en consecuencia me da igual
    // el que está más lejos. Si voy a sumar de todas formas. Entonces nomás lo dicho con vector y chau