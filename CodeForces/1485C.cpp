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

const int MAXN  = 1e5+5;
const int TOP = 50000;

int main() {
    FAST_IO;

    int aux; cin >> aux;
    forn(o,aux) {
        int x,y; cin >> x >> y;

        ll rta = 0;
        forsn(t,1,min(TOP,y+1)) {
            int low = t+1, high = y;
            while (high-low > 1) {
                int mid = (high+low)/2;
                if (((ll)t*mid + t) <= x) low = mid;
                else high = mid;
            }
            if (((ll)t*high + t) <= x) low = high;
            if (((ll)t*low + t) <= x) rta += low-t;
        }

        cout << rta << '\n';

    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
