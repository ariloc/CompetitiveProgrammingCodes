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

const int MAXN = 1e5+5;
const int MULT = 1e5;
const int MAXO = 205;
const int INF = 1e9+5;

struct op {
    int typ;
    ll v;
    int times;
};

ii dp[MAXN]; // llegado a este con el i-ésimo movimiento, siendo que ya lo usé j veces
op inp[MAXO];

ll makeOp (int x, int ind) {
    if (inp[ind].typ == 1) 
        return x+(inp[ind].v/MULT)+((inp[ind].v%MULT) > 0);

    ll r = (x*inp[ind].v);
    return r/MULT + ((r%MULT) > 0);
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) cin >> inp[i].typ >> inp[i].v >> inp[i].times;

    forsn(i,1,m+1) dp[i] = {INF,INF}; // skippeo el primero especialmente
    
    forn(i,m+1) {
        if (dp[i].fst != INF) {
            if (dp[i].snd+1 <= inp[dp[i].fst].times) {
                ll x = makeOp(i,dp[i].fst);
                if (x >= 0 && x <= m && 
                    (dp[i].fst < dp[x].fst || (dp[i].fst == dp[x].fst && dp[i].snd+1 < dp[x].snd)))
                        dp[x] = {dp[i].fst,dp[i].snd+1};
            }
            forsn(j,dp[i].fst+1,n) {
                ll x = makeOp(i,j);
                if (x >= 0 && x <= m && j <= dp[x].fst) // como es el primer salto, es siempre óptimo incluso si es igual
                    dp[x] = {j,1};
            }
        }
    }

    forsn(i,1,m+1) cout << (dp[i].fst == INF ? -1 : dp[i].fst+1) << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!