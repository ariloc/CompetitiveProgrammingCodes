#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
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

const int MAXN = 302;
const int MAXM = 1e6+5;

int arr[MAXN];
bitset<MAXM> mark;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) cin >> arr[j];

        if (n == 1) {cout << "1\n"; continue;}
        forn(j,MAXM) mark[j] = 0; // reset

        /* a ≡ b (mod m) si (a-b) ≡ 0 (mod m), es decir, si a-b es múltiplo de m.
           Por lo tanto si m es un divisor de (a-b), (a-b) será múltiplo de m
           en consecuencia, para que los números sean todos distintos, m no tiene que
           ser divisor de (a-b) siendo a y b cualquier par de valores del input.*/
        forn(j,n) forn(k,n) {
            int v = arr[j]-arr[k];
            for (int d = 1; d*d <= v; d++)
                if (!(v%d)) {mark[d] = true; if (v >= 0) mark[v/d] = true;}
        }

        int choose = -1;
        forsn(j,n,MAXM) if (!mark[j]) {choose = j; break;} // desde n ya que si no seguro hay una superposición

        cout << choose << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
