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

const int MAXN = 3e5+5;

vector<ii> edges;
pair<ii,int> scores[MAXN],inp[MAXN];
ll rta[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) cin >> scores[i].fst.fst >> scores[i].fst.snd, scores[i].snd = i, inp[i] = scores[i];
    forn(i,m) {
        int u,v; cin >> u >> v; u--, v--;
        edges.pb({u,v});
    }

    sort(scores,scores+n,[](const auto &lhs, const auto &rhs){return lhs.fst.fst+rhs.fst.snd < lhs.fst.snd+rhs.fst.fst;}); // es mayor si cuando hago yo el problema 1, el resultado es óptimo
    ll acc = 0;
    dforn(i,n) {
        rta[scores[i].snd] += acc+scores[i].fst.fst*(ll)(n-i-1);
        acc += scores[i].fst.snd;
    }
    acc = 0;
    forn(i,n) {
        rta[scores[i].snd] += acc+scores[i].fst.snd*(ll)i;
        acc += scores[i].fst.fst;
    }

    for (auto &i : edges) {
        ll calc = min(inp[i.fst].fst.fst+inp[i.snd].fst.snd,inp[i.fst].fst.snd+inp[i.snd].fst.fst);
        rta[inp[i.fst].snd] -= calc, rta[inp[i.snd].snd] -= calc;
    }

    forn(i,n) cout << rta[i] << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
