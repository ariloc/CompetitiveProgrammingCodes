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
const int MAXK = log2(MAXN)+2;

int P[2][MAXN], actT = 1;
int FA[MAXN],LA[MAXN],L[MAXN]; // euler tour, first appear, last appear, lvl for each
vi appear[MAXN],G[MAXN];
ii query[MAXN];

void dfs (int st, int lvl) {
    L[st] = lvl;
    FA[st] = LA[st] = actT;
    appear[lvl].pb(actT++); // queda ordenado

    for (auto &i : G[st]) {
        dfs(i,lvl+1);
        LA[st] = actT++;
    }
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(j,n) {cin >> P[0][j+1]; G[P[0][j+1]].pb(j+1);}
    P[0][0] = 0;

    int m; cin >> m;
    forn(j,m) cin >> query[j].fst >> query[j].snd;
    forsn(i,1,MAXK) { // binary lifting
        forn(j,m) if (query[j].snd&(1<<(i-1)))
            query[j].fst = P[(i-1)&1][query[j].fst];
        forsn(j,1,n+1) P[i&1][j] = P[(i-1)&1][P[(i-1)&1][j]];
    }

    dfs(0,0); // se le conectan todos los sin padres

    forn(j,m) {
        if (!query[j].fst) {cout << "0 "; continue;}
        int intendLvl = L[query[j].fst]+query[j].snd;
        int r = lower_bound(all(appear[intendLvl]),LA[query[j].fst])-appear[intendLvl].begin();
        int l = upper_bound(all(appear[intendLvl]),FA[query[j].fst])-appear[intendLvl].begin();
        cout << max(0,r-l-1) << ' '; // resto uno porque no me cuento a mi mismo
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
