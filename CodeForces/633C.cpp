#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const ll MAXL = 31;
const int MAXN = 100105;
const ll MOD = 1e9+7;

map<ll,string> rabinK; // mapeo de hashing de RabinKarp
ll found[MAXN];

void show(int st) { // desde el final tendré mi string resultado, muestro recusivamente desde el start
    if (!st) return;
    string x = rabinK[found[st]];
    show (st-x.size());
    cout << x << ' ';
}

int main() {
    FAST_IO;
    memset(found,-1,sizeof(found));

    int N; cin >> N;
    string s; cin >> s;
    int M; cin >> M;

    forn (i,M) {
        string x; cin >> x;
        ll n = 0;
        forn (j,x.size()) n = (n*MAXL + tolower(x[j]));
        // hashing -> accum + accum * cantidad total de caracteres posibles + caracter en si (repres ASCII)
        rabinK[n] = x;
    }

    found[0] = 0; // un principio del cual agarrar
    /* el for ve todas las posibilidades de palabras enganchadas empezando en el inicio,
     y terminando en el final, con todas consecutivas, y así valido. Puede que sobreescriba
     pero cualquier alternativa es válida. */
    forn (i,N) {
        ll val = 0;
        dforn (j,i+1) {
            val = (val*MAXL + s[j]); // RabinKarp again, probando
            if (found[j] != -1 and rabinK.count(val)) {
                // solo voy a pegar la palabra si tiene otra adyacente y está en el diccionario
                found[i+1] = val; // marco palabra que pega con otra, para chequear después
                break;
            }
        }
    }

    show(N); // como empecé del princpio y quiero ver las que conectan al final, recursivo para que me de el orden

    return 0;
}