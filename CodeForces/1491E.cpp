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
const int MAXF = 28;

bitset<MAXN> done,prohib,doneCnt;
int fibo[MAXF],isFromFib[MAXN];
vector<ii> G[MAXN];
int toCut = -1;

void precalcFibo() {
    fibo[0] = fibo[1] = 1;
    forsn(i,2,MAXF) fibo[i] = fibo[i-1] + fibo[i-2];
    forn(i,MAXN) isFromFib[i] = -1; // init
    forn(i,MAXF) if (fibo[i] < MAXN) isFromFib[fibo[i]] = i; // el 0 luego lo reemplaza el 1, en ind
}

int dfsCnt (int st) {
    doneCnt[st] = 1;

    int s = 0;
    for (auto &i : G[st]) if (!doneCnt[i.fst] && !prohib[i.snd]) s += dfsCnt(i.fst);

    return s+1;
}

int dfs (int st, int n, int p = -1) {
    done[st] = true;

    int s = 1;
    for (auto &i : G[st]) if (!done[i.fst] && !prohib[i.snd]) s += dfs(i.fst,n,i.snd);

    if (n-s < 0) return s;

    int aux1 = isFromFib[s], aux2 = isFromFib[n-s];
    if (aux1 != -1 && aux2 != -1 && abs(aux1-aux2) <= 1 && p != -1) toCut = p;
    return s;
}

int main() {
    FAST_IO;

    precalcFibo();

    int n; cin >> n;

    int idx = -1;
    forsn(i,1,MAXF) if (fibo[i] == n) {idx = i; break;}
    if (idx == -1) return cout << "NO", 0;

    forn(i,n-1) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb({v,i}), G[v].pb({u,i}); // démosle ids a las aristas para poder prohibirlas
    }

    bool posib = true;
    for (;;) {
        done.reset(), doneCnt.reset();
        vi cutQ;
        forn(j,n) {
            if (done[j]) continue;
            int nod = dfsCnt(j);
            if (isFromFib[nod] == -1) {posib = false; break;}
            if (nod == 1) continue;

            toCut = -1;
            dfs(j,nod);
            if (toCut == -1) {posib = false; goto OUT;}
            cutQ.pb(toCut);
        }
        if (cutQ.empty()) break;
        while (!cutQ.empty()) prohib[cutQ.back()] = true, cutQ.pop_back();
    }

    OUT:
    cout << (posib ? "YES" : "NO");

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
