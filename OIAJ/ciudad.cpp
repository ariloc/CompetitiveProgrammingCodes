#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < ll(n); i++)
#define forsn(i,s,n) for(ll i = ll(s); i < ll(n); i++)
#define dforn(i,n) for (ll i = ll(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = ll(n)-1; i >= ll(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e4+2;

struct nodo {
    int v,d;
    int obstruido;

    bool operator< (const nodo &o) const{
        return o.d < d;
    }
};

vector<nodo> G[MAXN];
int dist[MAXN][3];

int B,g,O;

struct nodo_dijkstra {
    int v,d;
    int obstruido;
    int cantObstruidos;
    vi camino;

    bool operator< (const nodo_dijkstra &o) const{
        return o.d < d;
    }
};

pair< vi, int > best = {{},-1};

void dijkstraBuscar (int st, int nd) {
    priority_queue<nodo_dijkstra> Q;
    Q.push({st,0,-1,0,{}});

    while (not Q.empty()) {
        auto x = Q.top(); Q.pop();

        if (x.v == nd) {
            if (best.snd == -1 or x.d < best.snd) {
                best.fst = x.camino;
                best.snd = x.d;
            }
            continue;
        }

        for (auto &w : G[x.v]){
            int obstruidos = x.cantObstruidos;

            if (w.obstruido != -1) {
                if (x.cantObstruidos >= 2) continue;
                obstruidos++;
            }

            if (not dist[w.v][obstruidos] or dist[w.v][obstruidos] > w.d + x.d) {
                bool upd = false;

                dist[w.v][obstruidos] = w.d + x.d;

                if (w.obstruido != -1) {x.camino.push_back(w.obstruido); upd = true;}
                Q.push({w.v, w.d+x.d, w.obstruido, obstruidos, x.camino});
                if (upd) x.camino.pop_back();
            }
        }
    }
}

int main() {
    freopen("ciudad.in","r",stdin);
    freopen("ciudad.out","w",stdout);

    scanf("%d %d %d",&B,&g,&O);

    forn (i,g) {
        int a,b,p;
        scanf("%d %d %d",&a,&b,&p);
        G[a].push_back({b,p,-1});
        G[b].push_back({a,p,-1});
    }

    forn (i,O) {
        int a,b,p;
        scanf("%d %d %d",&a,&b,&p);
        G[a].push_back({b,p,(int)i+1});
        G[b].push_back({a,p,(int)i+1});
    }

    dijkstraBuscar(1,B);

    vi obstruidos;
    for (auto &i : best.fst)
        obstruidos.push_back(i);

    if (!obstruidos.size()) printf("1 ");
    else if (obstruidos.size() == 1) printf("2 ");
    else if (obstruidos.size() == 2) printf("3 ");

    forn (i,obstruidos.size())
        printf("%d ",obstruidos[i]);

    printf("%d",best.snd);

    return 0;
}
