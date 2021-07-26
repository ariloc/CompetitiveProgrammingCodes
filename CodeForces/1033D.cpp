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

const int MOD = 998244353;
const int MAXN = 505;
const ll TOP_FORTH_ROOT = 5e4;
const ll TOP_CUBIC_ROOTS = 2e6;

map<ll,int> F;
vector<ll> arr;
bitset<TOP_CUBIC_ROOTS> done;
vector<ll> upToCbrt_primes;

ll pow4 (ll x) {
    return x*x*x*x;
}

void criba() { // me guardo los primos hasta aprox raíz cúbica de la cota del número
    for (ll i = 4; i < TOP_CUBIC_ROOTS; i += 2) done[i] = true;
    for (ll i = 3; i < TOP_CUBIC_ROOTS; i += 2)
        if (!done[i])
            for (ll j = i+i; j < TOP_CUBIC_ROOTS; j += i)
                done[j] = true;

    forsn(i,2,TOP_CUBIC_ROOTS) 
        if (!done[i]) upToCbrt_primes.pb(i);
}

int main() {
    criba();

    int n; scanf("%d",&n);

    // caso 3 divisores -> p^2 con p primo 
    // caso 4 divisores -> 
        // p^3
        // p_1 * p_2 con p_1 y p_2 primos
    // caso 5 divisores ->
        // p^4
        // p_1^2 * p_2 con p_1 y p_2 primos

    forn(i,n) {
        ll x; scanf("%lld",&x);

        ll low = 0, high = TOP_FORTH_ROOT;
        while (high-low > 1) {
            ll mid = (high+low)/2;

            if (pow4(mid) >= x) high = mid;
            else low = mid;
        }

        if (pow4(low) >= x) high = low;
        if (pow4(high) == x) {F[high] += 4; continue;}

        ll r_cub = cbrtl(x);
        if (r_cub*r_cub*r_cub == x) {F[r_cub] += 3; continue;}

        ll raiz = sqrtl(x);
        if (raiz*raiz == x) {F[raiz] += 2; continue;}
        
        // si llegué hasta acá, no es potencia, y tiene más de 3 divisores
        arr.pb(x);
    }

    // los siguientes tienen 4 o 5 divisores, son todos distintos

    forn(i,arr.size()) { // para aquellos con 5 divisores, puedo sacarle alguno seguro
        for (auto &j : upToCbrt_primes) {
            if (!(arr[i]%j)) { // si lo divide
            //cerr << arr[i] << ' ' << j << endl;
                ll aux = arr[i];
                if (!(aux%(j*j))) { // si agarré el cuadrado
                    aux /= (j*j); F[j] += 2; // me lo marco
                    F[aux]++; // y lo que queda es un primo
                    arr[i] = 1; // invalido el original
                    break; // y me voy
                }
                else {
                    aux /= j; // lo divido
                    ll raiz = sqrt(aux); // me fijo si agarré el otro
                    if (raiz*raiz == aux) { // eso se cumple si lo que me queda es un cuadrado de algo
                        F[j]++, F[raiz] += 2; // en dicho caso, me los marco
                        arr[i] = 1; // invalido
                        break; // y me voy
                    }

                    // notar que si justo agarré el primo de uno que es de 4 divisores, acá no lo toco, para saber mejor después
                }
            }
            //while (!(arr[i]%j)) F[j]++, arr[i] /= j;
        }
    }

    // por lo que hice antes, si o si acá son de dos divisores
    vector<ll> twoDiv, divided_cnt;
    forn(i,arr.size())
        if (arr[i] > 1) 
            twoDiv.pb(arr[i]), divided_cnt.pb(0); 

    //forn(i,twoDiv.size()) cerr << twoDiv[i] << ' ' << endl;

    // ahora los que me hayan quedado > 1, tienen exactamente dos divisores
    // pruebo de a pares para sacar lo que queda con __gcd()
    
    forn(i,twoDiv.size()) {
        if (twoDiv[i] > 1) { // puedo haberlo ya sacado todo a este punto
            set<ll> myDivs;
            forsn(j,i+1,twoDiv.size()) {
                if (twoDiv[i] != twoDiv[j]) {
                    ll dcm = __gcd(twoDiv[i],twoDiv[j]);
                    if (dcm == 1) continue; // claramente esto puede correr infinitamente sino
                    while (!(twoDiv[j]%dcm)) twoDiv[j] /= dcm, F[dcm]++, divided_cnt[j]++;
                    myDivs.insert(dcm);
                }
            }

            if (myDivs.count(1)) myDivs.erase(1); // por seguridad
            for (auto &j : myDivs)
                while (!(twoDiv[i]%j)) twoDiv[i] /= j, F[j]++, divided_cnt[i]++;
        }
    }

    if (F.count(1)) F.erase(1); // nuevamente, por seguridad

    // intento matarlo con los factores que haya encontrado
    forn(i,twoDiv.size()) {
        for (auto &j : F)
            while (!(twoDiv[i]%j.fst)) twoDiv[i] /= j.fst, F[j.fst]++, divided_cnt[i]++;
    }

    map<ll,vector<ll>> dummies_used;
    ll dummy = 4; // nunca será primo, uso los mútliplos de dos para reflejar el primo desconocido
    forn(i,twoDiv.size()) 
        if (twoDiv[i] > 1) {
            if (!dummies_used.count(twoDiv[i]))
                while (divided_cnt[i] < 2) {
                    divided_cnt[i]++;
                    dummies_used[twoDiv[i]].pb(dummy);
                    F[dummy]++, dummy += 2; // para los que me hayan sobrado, sea uno o dos
                }
            else for (auto &j : dummies_used[twoDiv[i]]) F[j]++; // por el tema de las repeticiones porque son los mismos primos
        }

    ll rta = 1;
    for (auto &i : F) rta = (rta * (i.snd+1))%MOD; // cerr << i.fst << ' ' << i.snd << endl;

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!