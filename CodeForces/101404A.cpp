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

const int MAXN = 102;

ii pers[MAXN];
int rta[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int p,n; cin >> p >> n;
        forn(j,n) cin >> pers[j].fst, pers[j].snd = j;
        forn(j,n) rta[j] = 0; // reset

        // primeros pueden pagar más
        sort(pers,pers+n,[](const ii &lhs, const ii &rhs){if (rhs.fst == lhs.fst) {return lhs.snd < rhs.snd;} return lhs.fst > rhs.fst;});

        int distrib = 0, notFull = n;
        bool posib = true;
        while (distrib < p) {
            if (!notFull) {posib = false; break;}
            int each = (p-distrib)/notFull;
            if (!each) each = 1; // si tengo muchos que pueden pagar
            int aux = notFull;
            forn(j,notFull) {
                if (distrib == p) break;
                int v = min({pers[j].fst-rta[pers[j].snd],each,p-distrib});
                distrib += v; rta[pers[j].snd] += v;
                if (rta[pers[j].snd] == pers[j].fst) aux--;
            }
            notFull = aux;
        }

        if (posib) forn(j,n) cout << rta[j] << " \n"[j == n-1];
        else cout << "IMPOSSIBLE\n";
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
