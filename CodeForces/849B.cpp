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

const int MAXN = 1005;

struct pt {
    int x,y;

    pt operator- (const pt &o) const {return {x-o.x, y-o.y};}
    void reduce() {
        int dcm = __gcd(x,y);
        x /= dcm, y /= dcm;
    }
    bool operator== (const pt &o) const {
        return (x == o.x && y == o.y);
    }
};

bitset<MAXN> done;
pt inp[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> inp[i].y, inp[i].x = i;

    bool posib = false;
    forn(k,2) { // por si justo el primero pertenece a uno de un punto separado
        forsn(j,k+1,n) { // pruebo todos los vectores
            pt vec = inp[j]-inp[k];
            vec.reduce();
            vi excluded;
            forn(i,n) {
                if (i == k) continue;
                pt tmp = inp[i]-inp[k];
                tmp.reduce();
                if (!(tmp == vec)) excluded.pb(i); // nos separamos los que no vayan en la línea del primero y del segundo
            }

            if (excluded.empty()) continue; // si es vacío, imposible porque el otro no tiene nada
            if (excluded.size() == 1) {posib = true; break;} // si es uno mando una paralela que pase por ahí y se puede
            bool broke = false;
            forsn(i,1,excluded.size()) { // si son más de 1, tienen que tener la misma tendencia que vec, porque la línea tiene que ser paralela a la otra
                pt tmp = inp[excluded[i]]-inp[excluded[0]];
                tmp.reduce();
                if (!(tmp == vec)) {broke = true; break;}
            }
            if (!broke) {posib = true; break;} // si todo se cumple, se puede y salgo
        }
    }

    cout << (posib ? "Yes" : "No");

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
