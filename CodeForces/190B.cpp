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

struct pt {
    ld x,y;

    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    pt operator+ (const pt &o) const {return {x+o.x,y+o.y};}
    pt operator* (const ld &o) const {return {x*o,y*o};}
    ld operator* (const pt &o) const {return x*o.x + y*o.y;} // dot product, escalar
    ld norm() {return *this**this;}
    ld norm2() {return sqrt(norm());}
};

int main() {
    FAST_IO;

    pt c1,c2; ld r1, r2;
    cin >> c1.x >> c1.y >> r1;
    cin >> c2.x >> c2.y >> r2;

    pt vec1 = c2-c1, vec2 = c1-c2;

    ld k = sqrt((r1*r1)/(vec1.x*vec1.x + vec1.y*vec1.y)); // el k tal que se cumple que está sobre la circunf c1 y está en la línea
    pt inter1 = c1 + vec1*k, inter2 = c1 + vec1*(-k); // intersección de circunf con línea

    k = sqrt((r2*r2)/(vec2.x*vec2.x + vec2.y*vec2.y)); // el k tal que se cumple que está sobre la circunf c2 y está en la línea
    pt inter3 = c2 + vec2*k, inter4 = c2 + vec2*(-k);

    ld rta = min({(inter1-inter3).norm2(),(inter1-inter4).norm2(),(inter2-inter3).norm2(),(inter2-inter4).norm2()})/2; // todas combs de sentidos así sacamos la mínima entre las dos intersec en c/circunf

    // verifiquemos si intersecan, porque en dicho caso la rta es 0. verificamos tanto en las x como en las ys
    bool inX = false, inY = false;
    ld izq1 = min(inter1.x,inter2.x), der1 = max(inter1.x,inter2.x), izq2 = min(inter3.x,inter4.x), der2 = max(inter3.x,inter4.x); // como medio que no hay que ponerlos en enteros si son flotantes, eh?
    if (izq1 > izq2) swap(izq1,izq2), swap(der1,der2);
    if (izq2 <= der1 && der2 >= der1) inX = true;

    izq1 = min(inter1.y,inter2.y), der1 = max(inter1.y,inter2.y), izq2 = min(inter3.y,inter4.y), der2 = max(inter3.y,inter4.y);
    if (izq1 > izq2) swap(izq1,izq2), swap(der1,der2);
    if (izq2 <= der1 && der2 >= der1) inY = true;

    if (inX && inY) rta = 0; // son colineales, tienen que intersecar las proys en ambos ejes

    cout << fixed << setprecision(15) << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
