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

bool maze[2][MAXN];
set<ii> conf[2];

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;
    forn(i,q) {
        int x,y; cin >> x >> y; x--; // dejo los y bien por comodidad
        maze[x][y] ^= 1;

        if (maze[x][y]) {
            if (maze[1^x][y-1]) conf[x].insert({y,y-1}), conf[1^x].insert({y-1,y});
            if (maze[1^x][y]) conf[x].insert({y,y}), conf[1^x].insert({y,y});
            if (maze[1^x][y+1]) conf[x].insert({y,y+1}), conf[1^x].insert({y+1,y});
        }
        else {
            if (maze[1^x][y-1]) conf[x].erase({y,y-1}), conf[1^x].erase({y-1,y});
            if (maze[1^x][y]) conf[x].erase({y,y}), conf[1^x].erase({y,y});
            if (maze[1^x][y+1]) conf[x].erase({y,y+1}), conf[1^x].erase({y+1,y});
        }

        cout << (conf[0].empty() && conf[1].empty() ? "Yes" : "No") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
