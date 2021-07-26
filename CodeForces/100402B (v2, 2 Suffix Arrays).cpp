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

const int MAXN = 520;
const int MAXA = 2*MAXN; // digamos que también es el alfabeto, duplicado
const int INF = 1e9;

vector<vi> mat;
vector<vi> shifts_horiz_rows[MAXN];
vector<vi> shifts_horiz_cols;
int shifts_vert[MAXN][MAXN]; // para la columna i-ésima, la posición del shift vertical j-ésimo en el orden

vector<vi> sort_cycle_shifts (const vi &s) { // para evitar overflow, vector<int> (vi)
    int n = (int)s.size();
    vi cnt(max(MAXA,n),0), perm(n), typ(n);
 
    forn(i,n) cnt[s[i]]++;
    forsn(i,1,MAXA) cnt[i] += cnt[i-1];
    forn(i,n) perm[--cnt[s[i]]] = i;
    typ[perm[0]] = 0;
    int typCnt = 1;
    forsn(i,1,n) {
        if (s[perm[i]] != s[perm[i-1]]) typCnt++;
        typ[perm[i]] = typCnt-1;
    }

    vi perm_aux(n), typ_aux(n);
    for (int k = 0; (1<<k) < n; k++) {
        forn(i,n) {
            perm_aux[i] = perm[i] - (1<<k);
            if (perm_aux[i] < 0) perm_aux[i] += n;
        }
        forn(i,typCnt) cnt[i] = 0;
        forn(i,n) cnt[typ[perm_aux[i]]]++;
        forsn(i,1,typCnt) cnt[i] += cnt[i-1];
        dforn(i,n) perm[--cnt[typ[perm_aux[i]]]] = perm_aux[i];
        typ[perm[0]] = 0;
        typCnt = 1;
        forsn(i,1,n) {
            ii act = { typ[perm[i]], typ[(perm[i] + (1<<k))%n] };
            ii prev = { typ[perm[i-1]], typ[(perm[i-1] + (1<<k))%n] };
            if (act != prev) typCnt++;
            typ_aux[perm[i]] = typCnt-1;
        }
        typ.swap(typ_aux);
    }
 
    // perm -> de menor a mayor, las posiciones en donde empiezan los cyclic shifts ordenados, de menor a mayor lexicográficamente en la string original
    // typ -> los "tipos" de cada uno de las posiciones dadas. Dos de mismo tipo significa que son lexicográficamente iguales.
    return {perm,typ};
}

int main() {
    FAST_IO;

    #ifdef ONLINE_JUDGE
        freopen("matrix.in","r",stdin);
        freopen("matrix.out","w",stdout);
    #endif

    string s; cin >> s;
    int n = (int)s.size();
    mat.resize(n,{});
    forn(i,n) mat[0].pb(s[i]);
    forsn(i,1,n) {cin >> s; forn(j,n) mat[i].pb(s[j]);}

    shifts_horiz_cols.resize(n,{});
    forn(i,n) {
        auto x = sort_cycle_shifts(mat[i]);
        vi aux;
        forn(j,n) shifts_horiz_cols[j].pb(x[1][j]); // lo hago string para poder procesarlo en mi versión de sort_cycle_shifts
        shifts_horiz_rows[i].swap(x);
    }

    vi aux2;
    forn(i,n)
        forn(k,2) forn(j,n) aux2.pb(shifts_horiz_cols[i][j]); // dos veces para tener toda substring

    auto x2 = sort_cycle_shifts(aux2);
    forn(i,n) forn(j,n) shifts_vert[i][j] = x2[1][i*2*n + j];

    vi rta(n*n,'z');
    forn(i,n) {
        vi best_shifts = {shifts_horiz_rows[i][0][0]};
        int typ = shifts_horiz_rows[i][1][shifts_horiz_rows[i][0][0]];
        forsn(j,1,n) 
            if ((shifts_horiz_rows[i][1][shifts_horiz_rows[i][0][j]]) == typ) // el mejor tipo
                best_shifts.pb(shifts_horiz_rows[i][0][j]);

        int best_vert = INF, shiftTry = -1;
        forn(j,best_shifts.size()) {
            int act = shifts_vert[best_shifts[j]][i];
            if (act < best_vert) best_vert = act, shiftTry = best_shifts[j];
        }

        vi aux;
        forn(j,n) forn(k,n) aux.pb(mat[(i+j)%n][(k+shiftTry)%n]);
        rta = min(rta,aux);
    }

    int ind = 0;
    forn(i,n) {forn(j,n) cout << (char)rta[ind++]; cout << '\n';}

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!