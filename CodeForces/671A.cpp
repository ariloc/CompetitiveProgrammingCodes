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

const int MAXN = 1e5+5;

struct pt {
    ll x,y;
    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    ll operator* (const pt &o) const {return x*o.x + y*o.y;}
    ll operator% (const pt &o) const {return x*o.y - y*o.x;}
    ll norm() {return *this**this;}
    ld norm2() {return sqrt(norm());}
};

struct ordIt {
    ld dif; int ind;

    bool operator< (const ordIt &o) const {
        return dif < o.dif;
    }
};

pt inp[MAXN];
ordIt byA[MAXN], byB[MAXN];

int main() {
    FAST_IO;

    pt a,b,t; cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
    int n; cin >> n;
    forn(i,n) cin >> inp[i].x >> inp[i].y;

    if (n == 1) return cout << fixed << setprecision(15) << (t-inp[0]).norm2() + min((inp[0]-a).norm2(),(inp[0]-b).norm2()), 0; // caso 1

    forn(i,n) {
        pt vec = (t-inp[i]);
        ld faux = vec.norm2(), daux1 = (a-inp[i]).norm2(), daux2 = (b-inp[i]).norm2();
        byA[i] = {daux1-faux,i};
        byB[i] = {daux2-faux,i};
    }

    sort(byA,byA+n); sort(byB,byB+n);

    ld full = 0;
    forn(i,n) full += (ld)2*(t-inp[i]).norm2();

    ld mini = full+min((a-t).norm2(),(b-t).norm2()); // consideremos también que podemos ya partir del tacho, y para eso mejor agarro la opción óptima (mínimo)
    forn(i,n) {
        int idx = 0;
        while (byA[i].ind == byB[idx].ind) idx++; // si no seguro siempre hay
        mini = min(mini,full + min({byA[i].dif + byB[idx].dif,byB[idx].dif,byA[i].dif})); // el caso ninguna lo tengo cubierto, asi que me fijo si me conviene agarrar 1 o 2 a la ida
    }

    cout << fixed << setprecision(15) << mini;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
