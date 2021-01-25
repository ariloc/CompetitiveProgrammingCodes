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
#define PI acos(-1)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

ld toRad (ld theta) {
    return theta*PI/180;
}

vector<pair<ld,ld>> inp;
vector<ld> rta;

int main() {
    FAST_IO;

    ld n,g; cin >> n >> g;

    forn(i,n) {
        ld d,theta; cin >> d >> theta;
        inp.push_back({d,theta});
    }

    forn(i,n) {
        ld v0 = 0;
        forsn(j,i,n) {
            ld d = inp[j].fst, theta = inp[j].snd;
            ld a = g*cos(toRad(theta));
            v0 = sqrt(v0*v0+2*a*d); // de despejar de fórmula de MRUV (Física)
        }
        rta.pb(v0);
    }

    for (auto &i : rta) cout << fixed << setprecision(10) << i << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
