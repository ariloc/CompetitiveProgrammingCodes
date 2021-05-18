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

const ll t_h_h = 36e11; // ticks de la manecilla de la hora en una hora
const ll t_m_m = 720e9;
const ll t_s_s = t_m_m;
const ll full_turn = t_h_h*12;

const ll INV_ELEVEN = 15709090909091;

ll mulmod (ll a, ll b, ll mod) {
    ll r = 0; a %= mod;
    while (b) {
        if (b&1) r = (r+a)%mod;
        a = (2*a)%mod; b >>= 1;
    }
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(o,t) {
        ll c[3]; cin >> c[0] >> c[1] >> c[2];

        // Supongamos todos los casos:
        bool posib = false;
        do {
            ll h = c[0], m = c[1], s = c[2];
            
            // sabiendo que la hora me dice la cantidad de nanosegundos, directamente despejo
            // Entonces x que roto resulta tiene que tener congruente con (m-12ns).11^-1 (mod full_turn)

            ll x = mulmod((m - mulmod(12,h,full_turn)), INV_ELEVEN, full_turn); // separo para evitar overflow

            ll hh = ((h+x+full_turn)%full_turn);
            ll mm = ((m+x+full_turn)%full_turn);
            ll ss = ((s+x+full_turn)%full_turn);
            ll ns = ss%t_s_s;

            //cerr << hh << ' ' << mm << ' ' << ss << endl;

            if (!(mm%12) && !(ss%720) && !(ns%720) && ((hh*12)%full_turn) == mm && ((mm*60)%full_turn) == ss) {
                //cerr << hh << ' ' << mm << ' ' << ss << endl;
                cout << "Case #" << o+1 << ": " << hh/t_h_h << ' ' << mm/t_m_m << ' ' << ss/t_s_s << ' ' << ns/720<< '\n';
                posib = true;
            }

        } while(next_permutation(c,c+3) && !posib);
    }
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!