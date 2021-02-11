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

const int X[] = {0,1,1};
const int Y[] = {0,-1,1};

vector<ii> marked;

int main() {
    FAST_IO;

    int q; cin >> q;
    forn(i,q) {
        marked.clear(); // reset

        int b,w; cin >> b >> w;

        int x = 2, y = (b > w ? 3 : 2);

        int auxx = x, auxy = y;
        forn(j,max(b,w)) {
            int ind = (j%3);
            marked.pb({auxx+X[ind],auxy+Y[ind]});
            if (ind == 2) auxx += 2; // para el próx paso
        }

        auxx = x+1, auxy = y;

        int cycles = max(b,w)/3 + ((max(b,w)%3) > 1);
        if (cycles > min(b,w)) {cout << "NO" << '\n'; continue;}

        forn(j,cycles)
            marked.pb({auxx,auxy}), auxx += 2;

        int cnt = min(b,w)-cycles;
        auxx = x;
        forn(j,cnt) {
            if (j&1) {
                marked.pb({auxx,auxy+1});
                auxx += 2;
            } else marked.pb({auxx,auxy-1});
        }

        cout << "YES\n";
        for (auto &j : marked) cout << j.fst << ' ' << j.snd << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!

