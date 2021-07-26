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

const int MAXA = 30;
const int MAXN = 520;
const int INF = 1e9;

struct dataMap {
    int typ, pos;
};

vector<string> mat;
vector<vi> shiftsRow[MAXN];
dataMap fromShift[MAXN][MAXN]; // para cada fila, para cada shifteo, su tipo correspondiente y su posición en el orden

vector<vi> sort_cycle_shifts (const string &s) { // ----> con s.size() una potencia 2^k
    int n = (int)s.size();
    vi cnt(max(MAXA,n),0), perm(n), typ(n), perm_aux(n), typ_aux(n);

    forn(i,n) cnt[s[i]-'a']++; // cuento la cantidad de c/letra
    forsn(i,1,MAXA) cnt[i] += cnt[i-1]; // acumulo cantidades
    forn(i,n) perm[--cnt[s[i]-'a']] = i; // le asigno a cada uno su posición en la permutación ordenada
    typ[perm[0]] = 0; // el tipo del primero es 0
    int typCnt = 1;
    forsn(i,1,n) {
        if (s[perm[i]] != s[perm[i-1]]) typCnt++; // aumentan la cantidad de tipos cuando hay una transición en la permutación ordenada
        typ[perm[i]] = typCnt-1; // el tipo es la cantidad, -1 por 0-indexed
    }

    for (int k = 0; (1<<k) < n; k++) { // juntando bloques de 2^k en aquellos de 2^(k+1), ordenando similarmente como antes
        forn(i,n) {
            perm_aux[i] = perm[i] - (1<<k); // considerando que ordeno los nuevos bloques por el segundo, comienzan entonces con el bloque a su izquierda
            if (perm_aux[i] < 0) perm_aux[i] += n; // es cíclico, entonces si me paso, me paso para el otro lado
        }
        forn(i,typCnt) cnt[i] = 0; // reset de los contadores
        forn(i,n) cnt[typ[perm_aux[i]]]++; // cuento en base a las clases de los bloques
        forsn(i,1,typCnt) cnt[i] += cnt[i-1];
        dforn(i,n) perm[--cnt[typ[perm_aux[i]]]] = perm_aux[i]; // posición ordenada de los bloques (lo de antes pero con los bloques de la forma establecida en perm_aux)
        typ[perm[0]] = 0;
        typCnt = 1; // vuelvo a contar tipos existentes desde 0
        forsn(i,1,n) {
            // los bloques nuevos los forman dos bloques de tamaño de una potencia menor, los represento con sus tipos (los abstraigo de esta forma)
            ii act = { typ[perm[i]], typ[(perm[i] + (1<<k))%n] };
            ii prev = { typ[perm[i-1]], typ[(perm[i-1] + (1<<k))%n] };
            if (act != prev) typCnt++; // nuevamente, si los tipos de los bloques en orden son distintos, entonces cuento un tipo de más
            typ_aux[perm[i]] = typCnt-1; // pongo los nuevos tipos en un arreglo auxiliar, así nos piso los viejos que todavía los estoy usando
        }
        typ.swap(typ_aux); // hecho todo, los tipos auxiliares ahora son los actuales
    }

    // perm -> de menor a mayor, las posiciones en donde empiezan los cyclic shifts ordenados, de menor a mayor lexicográficamente en la string original
    // typ -> los "tipos" de cada uno de las posiciones dadas. Dos de mismo tipo significa que son lexicográficamente iguales.
    return {perm,typ};
}

int main() {
    FAST_IO;

    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);

    string s; cin >> s; mat.pb(s);
    int n = (int)s.size();
    forn(i,n-1) cin >> s, mat.pb(s);

    forn(i,n) {
        shiftsRow[i] = sort_cycle_shifts(mat[i]); // obtengo el suffix array por cada fila
        vi aux_typ(shiftsRow[i][1].size());
        forn(j,n) aux_typ[j] = shiftsRow[i][1][shiftsRow[i][0][j]];
        swap(aux_typ,shiftsRow[i][1]);
    }
    forn(i,n) forn(j,n)
        fromShift[i][shiftsRow[i][0][j]] = {shiftsRow[i][1][j],j}; // para cada shifteo, el tipo que le corresponde y la posición en el orden

    string rta = string(n*n,'z');
    forn(i,n) { // suponiendo que la i-ésima fila es la de arriba de todo
        vi valids;
        int myTyp = shiftsRow[i][1][0];
        forn(j,n) // de entre los primeros, me agarro como posibles todos con un mismo "tipo" (lexic. iguales)
            if (shiftsRow[i][1][j] == myTyp) // si los que le siguen son igual al tipo del primero
                valids.pb(shiftsRow[i][0][j]);

        int actRow = i, actTyp = -1, min_posic = INF;
        vi valids_aux;
        forn(j,n) { // para las siguientes filas, cuáles son los mejores que existen en próximas filas de los válidos de antes? -> considerando casos varios lexic. iguales
            actRow = (actRow+1)%n;
            valids_aux.clear(), actTyp = -1, min_posic = INF; // reset por cada fila

            for (auto &k : valids) {
                dataMap x = fromShift[actRow][k]; // el tipo y la posición de menor a mayor según el shifteo en esta fila
                if (x.pos < min_posic) { 
                    min_posic = x.pos;// si la posición es menor, actualizo porque encontré una buena

                    if (x.typ != actTyp) // puede ser menor posición pero un tipo ya registrado, caso contrario son de un tipo lexic. mejor y mato lo de antes
                        actTyp = x.typ, valids_aux.clear();
                }
                if (x.typ == actTyp) valids_aux.pb(k); // me meto si soy del mismo tipo que el mejor registrado
            }
            valids.swap(valids_aux);
        }

        // una vez que llegué acá, cualquiera de los shifts en valids debe ser óptimo suponiendo que la i-ésima fila es la superior
        int shiftTry = valids[0];
        string bestMe;
        forn(j,n) forn(k,n) bestMe.pb(mat[(i+j)%n][(shiftTry+k)%n]);
        rta = min(rta,bestMe);
    }

    int ind = 0;
    forn(i,n) {forn(j,n) cout << rta[ind++]; cout << '\n';}

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!