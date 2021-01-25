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

const int MAXN = 3e5+2;
const int INF = 1e9+5;

int road[MAXN];
vector<pair<int,bool>> ranges[MAXN];
vector<ii> rta;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> road[i];

    int r = 0;
    forn(l,n) { // todos los rangos máximos que empiezan en l
        while (r < n && road[r]-r-1+l >= 0) r++;
        ranges[l].pb({r-1,0});
    }

    int l = n-1;
    dforn(rr,n) { // todos los que terminan en r
        while (l >= 0 && road[l]-rr+l-1 >= 0) l--;
        ranges[l+1].pb({rr,1});
    }

    int toCheck = 0, maxi = -1, prvnd = -1, indst = -1; bool flip = false;
    forn(i,n) {
        forn(j,ranges[i].size()) {
            auto e = ranges[i][j];
            if (e.fst > maxi) maxi = e.fst, indst = i, flip = e.snd;
        }
        if (toCheck == i) {
            int a = max(indst,prvnd+1), b = maxi;
            prvnd = maxi;
            if (flip) swap(a,b);
            rta.pb({a,b}); toCheck = maxi+1;
            if (toCheck >= n) break;
        }
    }

    cout << rta.size() << '\n';
    for (auto &i : rta) cout << i.fst+1 << ' ' << i.snd+1 << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
