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

const int MAXN = 1e5+5;
const int INF = 1e9+5;
const int MAXST = (1<<(32-(__builtin_clz(2*MAXN))));

int costs[MAXN],F[MAXN],L[2*MAXN],No[2*MAXN],actT = 0; // First aparic, Level of time, Node of time
bitset<MAXN> done;
ii ST[2*MAXST];
ll sums[MAXN];
vi G[MAXN];
int myRoot = 0;

void dfs(int st, int lvl, ll sum) {
    done[st] = true;
    No[actT] = st;
    L[actT] = lvl;
    F[st] = actT++;
    for (auto &i : G[st]) {
        if (done[i]) continue;
        dfs(i,lvl+1,sum+costs[st]);
        No[actT] = st;
        L[actT++] = lvl;
    }
    sums[st] = sum+costs[st];
}

/*ii operator< (const ii &a, const ii &b) {
    if (a.snd < b.snd) return a;
    return b;
}*/

ii query(int i, int tl, int tr, int bl, int br) {
    if (tl >= br or tr <= bl) return {INF,INF};
    if (tl >= bl and tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return min(query(2*i,tl,mid,bl,br),query(2*i+1,mid,tr,bl,br));
}

void iniciarNivel(vector<int> M, vector<int> a, vector<int> b) {
    forn(i,M.size()) costs[i] = M[i];
    forn(i,a.size()) {
        G[a[i]].pb(b[i]);
        G[b[i]].pb(a[i]);
    }
    //if (a.size() > 1) {
        forn(i,M.size()) if ((int)G[i].size() <= 1) {myRoot = i; break;} // defino una raíz
        //myRoot = a[0]; // defino una raíz
        dfs(myRoot,0,0); // sumo dists y hago euler a la vez
        forn(i,actT) ST[i+MAXST] = {L[i],i}; // nodo con el nivel corresp
        dforsn(i,1,MAXST) ST[i] = min(ST[2*i],ST[2*i+1]);
    //}
    //forn(i,actT) cerr <<No[i] << ' ' << L[i] << endl;
}


long long eleccion(int c, int d)
{
    //if (!sz) return costs[c];
    int a = F[c], b = F[d];
    if (a > b) swap(a,b);
    //cerr << "OKK" << ' ' <<a << ' ' << b <<endl;
    ii LCA = query(1,0,MAXST,a,b+1);
    int nod = No[LCA.snd];
    //cerr << LCA.fst << endl;
    //cerr << c << ' ' << d << ' ' << sums[c] << ' ' << sums[d] << ' ' << sums[LCA.fst] << ' ' << LCA.fst << endl;
    return sums[c]+sums[d]-2*(sums[nod])+costs[nod];
}

long long eleccion(int c, int d);

int main()
{
    int N;
    cin>>N;
    vector<int> M(N);
    for(int i = 0; i < N; i++) cin>>M[i];
    vector<int> a(N - 1), b(N - 1);
    for(int i = 0; i < N - 1; i++) cin>>a[i]>>b[i];
    iniciarNivel(M, a, b);
    int Q;
    cin>>Q;
    for(int i = 0; i < Q; i++)
    {
        int c, d;
        cin>>c>>d;
        cout<<eleccion(c, d)<<endl;
    }
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
