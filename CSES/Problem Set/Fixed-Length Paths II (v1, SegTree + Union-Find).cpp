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
 
const int MAXN = 2e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
const int INF = 2e9;
 
void fs (int &x) {
    x = 0;
    int c; c = getchar();
    if (c < '0' || c > '9') c = getchar();
    for(; c >= '0' && c <= '9'; c = getchar())
        x = 10*x + c-'0';
}
 
int n,k1,k2;
ll rta = 0;
 
struct nodo {
    int l,r,sum,p;
    nodo() : l(-1), r(-1), sum(0), p(-1) {};
};
 
struct SegT {
    vector<nodo> bag;
 
    SegT() : bag({nodo()}) {};
 
    int newNode (int i) { // bolsa de nodos, pero no es persistent segtree
        if (i == -1) {bag.pb(nodo()); return (int)bag.size()-1;}
        return i;
    }
 
    int update (int i, int p, int v, int tl = 0, int tr = MAXST) {
        if (tl > p || tr <= p) return i;
        i = newNode(i);
 
        if (tr-tl == 1) { // cuando lo creo, debe saber quién es
            bag[i].sum += v, bag[i].p = p;
        }
        else {
            int mid = (tl+tr)/2;
            bag[i].l = update(bag[i].l,p,v,tl,mid);
            bag[i].r = update(bag[i].r,p,v,mid,tr);
            bag[i].sum = (bag[i].l == -1 ? 0 : bag[bag[i].l].sum) + (bag[i].r == -1 ? 0 : bag[bag[i].r].sum);
        }
 
        return i;
    }
 
    int query (int i, int bl, int br, int tl = 0, int tr = MAXST) {
        if (tl >= br || tr <= bl || i == -1) return 0;
        if (tl >= bl && tr <= br) return bag[i].sum;
 
        int mid = (tl+tr)/2;
        return query(bag[i].l,bl,br,tl,mid) + query(bag[i].r,bl,br,mid,tr);
    }
};
 
struct dato {
    SegT ST;
    int minDep;
};
 
struct DS {
    vi p,r;
    vector<dato> cmp;
 
    void init(int N) {
        p.assign(N,0);
        r.assign(N,0);
        cmp.assign(N,{SegT(),INF});
        forn(i,N) p[i] = i;
    }
 
    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}
 
    void merge (int y, int x) {
        int m_minDep = min(cmp[x].minDep,cmp[y].minDep);
        vector<ii> toUpd;
 
        for (auto &i : cmp[x].ST.bag) {
            if (i.p != -1) { // si es una hoja
                int left = k1-i.p+2*m_minDep;
                int right = k2-i.p+2*m_minDep; // se pueden ir a negativos o positivos, pero como el ST busca en un rango dado, no hay drama
                int tot = cmp[y].ST.query(0,left,right+1);
 
                rta += (ll)tot * i.sum;
 
                toUpd.pb({i.p, i.sum});
            }
        }
 
        for (auto &i : toUpd) cmp[y].ST.update(0,i.fst,i.snd); 
        cmp[y].minDep = m_minDep;
    }
 
    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; merge(y,x);
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};
 
vi G[MAXN];
bitset<MAXN> done;
DS UF;
 
void dfs1 (int st, int lvl) {
    done[st] = true;
 
    UF.cmp[st].minDep = lvl;
    UF.cmp[st].ST.update(0,lvl,1);
 
    for (auto &i : G[st]) 
        if (!done[i]) {
            dfs1(i,lvl+1);
            UF.join(st,i);
        }
}
 
int main() {
    fs(n), fs(k1), fs(k2);
    
    UF.init(n+2);
 
    forn(i,n-1) {
        int u,v; fs(u), fs(v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
 
    dfs1(0,0);
 
    printf("%lld",rta);
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!