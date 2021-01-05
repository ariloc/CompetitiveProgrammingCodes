#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
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

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 102;

char grid[MAXN][MAXN];
vector<vector<ii>> rta;

void clearSq(int j, int k) {
    vector<ii> onBits;

    forn(l,4) {
        onBits.clear();
        if (grid[j][k] == '1') onBits.pb({j,k});
        if (grid[j+1][k] == '1') onBits.pb({j+1,k});
        if (grid[j][k+1] == '1') onBits.pb({j,k+1});
        if (grid[j+1][k+1] == '1') onBits.pb({j+1,k+1});

        if (onBits.empty()) break;

        if ((int)onBits.size() == 4 || (int)onBits.size() == 3) {
            rta.pb({onBits[0],onBits[1],onBits[2]});
            forn(o,3) grid[onBits[o].fst][onBits[o].snd] = '0';
        }
        else { // == 2 || == 1
            int cnt = 0; vector<ii> tmp;
            forn(g,2) forn(h,2)
                if (cnt < 2 && grid[j+g][k+h] == '0') {
                    grid[j+g][k+h] = '1'; cnt++;
                    tmp.pb({j+g,k+h});
                }
            tmp.pb(onBits[0]);
            grid[onBits[0].fst][onBits[0].snd] = '0';
            rta.pb(tmp);
        }
    }
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;
        forn(j,n) forn(k,m) cin >> grid[j][k];
        rta.clear(); // reset

        forn(j,n-2) forn(k,m-2) { // despejamos centro
            if (grid[j][k] == '1') {
                grid[j][k] = '0';
                grid[j+1][k] = (grid[j+1][k] == '0' ? '1' : '0');
                grid[j][k+1] = (grid[j][k+1] == '0' ? '1' : '0');
                rta.pb({{j,k},{j+1,k},{j,k+1}});
            }
        }

        forn(j,n-2) { // corremos lado derecho
            if (grid[j][m-2] == '1' || grid[j][m-1] == '1') {
                vector<ii> tmp;
                forn(g,2) forn(h,2)
                    if ((int)tmp.size() < 3 && grid[j+g][m-2+h] == '1')
                        tmp.pb({j+g,m-2+h});
                forn(h,2)
                    if ((int)tmp.size() < 3 && grid[j+1][m-2+h] == '0')
                        tmp.pb({j+1,m-2+h});
                rta.pb(tmp);
                for (auto &k : tmp) grid[k.fst][k.snd] = (grid[k.fst][k.snd] == '0' ? '1' : '0');
            }
        }

        forn(j,m-2) { // corremos lado inferior
            if (grid[n-1][j] == '1' || grid[n-2][j] == '1') {
                vector<ii> tmp;
                forn(g,2) forn(h,2)
                    if ((int)tmp.size() < 3 && grid[n-2+h][j+g] == '1')
                        tmp.pb({n-2+h,j+g});
                forn(h,2)
                    if ((int)tmp.size() < 3 && grid[n-2+h][j+1] == '0')
                        tmp.pb({n-2+h,j+1});
                rta.pb(tmp);
                for (auto &k : tmp) grid[k.fst][k.snd] = (grid[k.fst][k.snd] == '0' ? '1' : '0');
            }
        }

        // ahora todos los bits están en el cuadrado 2x2 de la esquina inferior derecha
        clearSq(n-2,m-2);

        cout << rta.size() << '\n';
        for (auto &j : rta) {
            for (auto &k : j) cout << k.fst+1 << ' ' << k.snd+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
