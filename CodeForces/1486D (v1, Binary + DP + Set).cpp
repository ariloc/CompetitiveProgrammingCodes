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

/* ya, la greedy no va (como pensaba) porque si vas sacando de los costados según la menor cantidad
   de diferencia a uno que este del lado izquierdo en nuestro rango, para sacarlo, puedo terminar sacando
   en el proceso a alguno grande que tal vez convenía en su momento pero tal vez los grandes que sacaba
   del otro lado no eran taaan grandes y la mediana que me termina quedando es menor.
   Pensé BS en la ventana pero ni a palo iba (es básicamente un two pointers)... así que BS en la solución...
   es CLAVE lo de AL MENOS cierto valor, y de ahí sale todo (OTRA COSA CLAVE, a_i <= n, medio una pistita)
*/

const int MAXN = 2e5+5;
const int INF = 1e9+5;

int arr[MAXN],dp[MAXN],n,k;
set<int> prefs;

bool isPosib (int mid) {
    // ah posta que kadane no va, porque puede pasar que después de neg luego es positivo y se puede k, entonces nada que ver
    // así que nomas vayamos sacando prefijos y vamos insertando en un set con un desfase de k...
    forn(i,n) dp[i] = 0;
    prefs.clear(); // reset
    int acc = 0;
    forn(i,n) {
        if (i-k == -1) prefs.insert(0);
        if (i-k >= 0) prefs.insert(dp[i-k]);
        acc += (arr[i] < mid ? -1 : 1);
        dp[i] = acc;
        auto it = prefs.lower_bound(acc);
        if (it != prefs.begin()) return true;
    }
    return false;
}

int main() {
    FAST_IO;

    cin >> n >> k;
    forn(i,n) cin >> arr[i];

    int low = 1, high = n;
    while (high-low > 1) {
        int mid = (high+low)/2;

        if (isPosib(mid)) low = mid;
        else high = mid;
    }

    if (isPosib(high)) cout << high;
    else cout << low;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
