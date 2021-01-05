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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;
        vector<ii> ids; map<int,int> marked;
        forn(j,m) {
            int r,c; cin >> r >> c; r--, c--;
            int v = 0;
            if (marked.count(c)) v = marked[c];
            marked[c] = v|(1<<r);
        }
        for (auto &j : marked) ids.pb({j.snd,j.fst});
        ids.pb({3,n}); // dummy

        bool posib = true;
        forn(j,ids.size()) {
            if (ids[j].fst != 3) {
                if ( (ids[j+1].fst == 3) ||
                     (ids[j].fst == ids[j+1].fst && !((ids[j+1].snd-ids[j].snd)&1)) ||
                     (ids[j].fst != ids[j+1].fst && ( ((ids[j+1].snd-ids[j].snd)&1) ||
                                                      ((ids[j+1].snd-ids[j].snd) <= 1) )) ) {posib = false; break;}
                j++; // skip one
            }
        }

        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
