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

const int MAXN = 250005;
const int INF = 1e9+5;

vi mat[MAXN];
int n,m;

bool solve(int dep);

bool tryMe (vi Q, int row, int dep) {
    vi og;
    for (auto &i : Q) og.pb(mat[0][i]), mat[0][i] = mat[row][i];
    forsn(i,1,n) {
        int cnt = 0;
        forn(j,m) if (mat[i][j] != mat[0][j]) cnt++;
        if (cnt > 2) goto NOPE;
    }

    return 1; // if everything works ok, no need to change

    NOPE:
    // si aún no puedo, aún nos queda la chance de que estamos con un Q.size() == 1, a lo que se nos permite un cambio más
    // cuando cambio una posición no importa cuál de todos de los de 3 agarro
    // si son todos iguales pero cambio otro de otro tamaño menor, tendré que ver en ese cómo hacer para no afectar
    // si simplemente todos los de 3 no tienen igual, entonces tendré que hacer dos cambios y ver correspondientemente
    // así en consecuencia llamamos de nuevo a la función
    // ah y btw da AC sin verificar Q.size()...pero se lo pongo igual por si termino haciendo en algún caso dos de 4 y está mal porque uso demasiados movs
    if ((int)Q.size() == 1 && solve(dep+1)) return 1; // salimos y no cambiamos nada

    forn(i,Q.size()) mat[0][Q[i]] = og[i]; // revert back if unsuccessful
    return 0;
}

bool solve(int dep) {
    if (dep > 1) return 0; // no puedo pasarme de dos llamadas, porque si no cambio más posic

    vi three, four; int row3 = -1, row4 = -1;
    forsn(i,1,n) {
        vi inds;
        forn(j,m) if (mat[i][j] != mat[0][j]) inds.pb(j);
        if ((int)inds.size() > 4) return 0; // ni con dos cambios puedo
        if (three.empty() && (int)inds.size() == 3) three = inds, row3 = i;
        if (four.empty() && (int)inds.size() == 4) four = inds, row4 = i;
    }

    if (!four.empty()) {
        forn(i,four.size()) forsn(j,i+1,four.size()) if (tryMe({four[i],four[j]},row4,dep)) return 1;
    }
    else if (!three.empty()) {forn(i,three.size()) if (tryMe({three[i]},row3,dep)) return 1;}
    if (four.empty() && three.empty()) return 1;
    return 0;
}

int main() {
    FAST_IO;

    cin >> n >> m;
    forn(i,n) forn(j,m) {
        int x; cin >> x;
        mat[i].pb(x);
    }

    if (solve(0)) goto OUT;

    return cout << "No", 0; // no pude hacer out, entonces no se puede (si es que había conflictos)

    OUT:
    cout << "Yes\n";
    for (auto &i : mat[0]) cout << i << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
