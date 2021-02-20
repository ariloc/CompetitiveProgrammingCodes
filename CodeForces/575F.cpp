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

const int MAXN = 5005;

ii lights[MAXN];

int minDist (ii light, int x) {
    if (x >= light.fst && x <= light.snd) return 0;
    return min(abs(light.fst-x),abs(light.snd-x));
}

ii intersec (ii a, ii b) {
    return {max(a.fst,b.fst), min(a.snd,b.snd)};
}

bool isValid (ii x) {
    return (x.fst <= x.snd);
}

int main() {
    FAST_IO;

    int n,x; cin >> n >> x;

    forn(i,n) cin >> lights[i].fst >> lights[i].snd;

    ll rta = 0;
    forn(i,n) {
        rta += minDist(lights[i],x);
        if (minDist(lights[i],x) > 0) { // si digamos el rango no me incluye
            ii actR = {x,(abs(lights[i].fst-x) < abs(lights[i].snd-x) ? lights[i].fst : lights[i].snd)}; // hacemos el rango donde puede estar x
            if (actR.fst > actR.snd) swap(actR.fst,actR.snd);

            int r = i+1;
            while (r < n && isValid(intersec(actR,lights[r]))) actR = intersec(actR,lights[r]), r++; // la intersección todo lo posible
            if (r < n && lights[r].fst > actR.snd) x = actR.snd; // agarramos el más cercano al sig que no interseca, si existe
            else x = actR.fst;
            i = r-1; // así después avanza al prox
        }
    }

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
